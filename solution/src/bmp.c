//
// Created by мак on 12.12.2024.
//

#include <bmp.h>

enum read_status from_bmp(FILE* in, struct image* img){
    struct bmp_header headers;

    if(fread(&headers, sizeof(struct bmp_header), 1, in) != 1 || headers.bfileSize <= 54)
        return READ_INVALID_HEADER;
    if (headers.biBitCount != 24 || headers.biPlanes != 1)
        return READ_INVALID_BITS;
    if (headers.bfType != 0x4D42)
        return READ_INVALID_SIGNATURE;

    img->height = headers.biHeight;
    img->width = headers.biWidth;
    img->data = malloc(img->height * sizeof(struct pixel*));
    if(img->data == NULL) return NOT_ENOUGH_MEMORY;

    for (size_t i = 0; i < img->height; ++i) {
        img->data[i] = malloc(img->width * sizeof(struct pixel));
        if(img->data[i] == NULL) return NOT_ENOUGH_MEMORY;
    }

    uint32_t padding_size = (4 - (img->width * 3) % 4) % 4;

    for(int i = 0; i < img->height; i++){
        for (size_t j = 0; j < img->width; j++) {
            size_t r = fread(&(img->data[i][j]), sizeof(struct pixel), 1, in);
            if(ferror(in))
                return READ_ERROR;
            if(r<=0)
                return READ_ERROR;
        }
        fseek(in,  padding_size, SEEK_CUR);
        if(ferror(in))
            return READ_ERROR;

    }

    return READ_OK;
}

//формирует заголовки и вызывает функцию записывания
enum write_status to_bmp(FILE* file, struct image* img){
    struct bmp_header header = {0};
    enum write_status result = WRITE_OK;
    header.bfType = 0x4D42;
    header.bOffBits = 54;
    header.biSize = 40;
    header.biHeight = img->height;
    header.biWidth = img->width;
    header.biPlanes = 1;
    header.biBitCount = 24;

    size_t padding_size = (4 - (header.biWidth * 3) % 4) % 4; // вычисляем количество байтов для выравнивания
    uint8_t  padding_byte = 0;

    header.biSizeImage = (header.biWidth * sizeof(struct pixel) + padding_size) * header.biHeight;
    header.bfileSize = 54 + header.biSizeImage;

    if(fwrite(&header, 54, 1, file) != 1)
        result = WRITE_ERROR;
    for (size_t i = 0; i < img->height; i++) {
        for (size_t j = 0; j < img->width; j++) {
            if(fwrite(&(img->data[i][j]), sizeof(struct pixel), 1, file) != 1)
                result = WRITE_ERROR;
        }
        for (size_t k = 0; k < padding_size; k++) {
            if(fwrite(&padding_byte, 1, 1, file) != 1)
                result = WRITE_ERROR;
        }
    }

    return result;
}

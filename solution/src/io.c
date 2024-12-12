//
// Created by мак on 12.12.2024.
//

#include <io.h>

enum read_status read_img(char* file_path, struct image* img){
    FILE * file = fopen(file_path, "rb");
    if(file == NULL)
        return READ_OPEN_FAIL;

    enum read_status result = from_bmp(file, img);
    fclose(file);

    return result;
}

enum write_status write_img(char* dest_path, struct image* dest_image){
    FILE* file = fopen(dest_path, "wb");
    if(file == NULL)
        return WRITE_OPEN_FAIL;

    enum write_status result = to_bmp(file, dest_image);
    fclose(file);

    return result;
}

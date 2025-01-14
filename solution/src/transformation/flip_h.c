//
// Created by мак on 12.12.2024.
//
#include <image.h>
#include <stdlib.h>

enum transformation_status flip_h(struct image* init_img, struct image* transformed_img){
    transformed_img->height = init_img->height;
    transformed_img->width = init_img->width;
    transformed_img->data = malloc(transformed_img->height * sizeof(struct pixel*));
    if(transformed_img->data == NULL) return TRANSFORMATION_MALLOC_FAIL;

//    struct pixel* pixel_space = malloc(transformed_img->height * transformed_img->width * sizeof(struct pixel));
//    if(pixel_space == NULL) return TRANSFORMATION_MALLOC_FAIL;
//
//    for (size_t i = 0; i < transformed_img->height; i++) {
//        transformed_img->data[i] = pixel_space + i*transformed_img->width;
//    }

    for (size_t i = 0; i < transformed_img->height; i++) {
        transformed_img->data[i] = malloc(transformed_img->width * sizeof(struct pixel));
        if(transformed_img->data[i] == NULL) return TRANSFORMATION_MALLOC_FAIL;
    }

    for (int i = 0; i < init_img->height; i++) {
        for (int j = 0; j < init_img->width; j++)
            transformed_img->data[i][init_img->width - 1 - j] = init_img->data[i][j];
    }

    return TRANSFORMATION_OK;
}

//
// Created by мак on 12.12.2024.
//
#include <image.h>
#include <stdlib.h>

struct transformation_result cw_90(struct image* init_img, struct image* transformed_img) {

    transformed_img->height = init_img->width;
    transformed_img->width = init_img->height;
    transformed_img->data = malloc(transformed_img->height * sizeof(struct pixel *));
    if (transformed_img->data == NULL) return (struct transformation_result){.status=TRANSFORMATION_MALLOC_FAIL, .image=NULL};

    struct pixel* pixel_space = malloc(transformed_img->height * transformed_img->width * sizeof(struct pixel));
    if(pixel_space == NULL) return (struct transformation_result){.status=TRANSFORMATION_MALLOC_FAIL, .image=NULL};

    for (int i = 0; i < transformed_img->height; i++){
        transformed_img->data[i] = pixel_space + i * transformed_img->width;
    }

    for (int i = 0; i < init_img->height; i++) {
        for (int j = 0; j < init_img->width; j++)
            transformed_img->data[init_img->width - 1 - j][i] = init_img->data[i][j];
    }

    return (struct transformation_result){.status=TRANSFORMATION_OK, .image=transformed_img};
}

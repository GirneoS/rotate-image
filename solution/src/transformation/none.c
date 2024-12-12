//
// Created by мак on 12.12.2024.
//

#include <image.h>
#include <stdlib.h>

void none(struct image* init_img, struct image* transformed_img){
    transformed_img->height = init_img->height;
    transformed_img->width = init_img->width;
    transformed_img->data = malloc(init_img->height * sizeof(struct pixel*));

    for (size_t i = 0; i < transformed_img->height; i++) {
        transformed_img->data[i] = malloc(transformed_img->width * sizeof(struct pixel));
    }

    for (size_t i = 0; i < transformed_img->height; i++) {
        for (size_t j = 0; j < transformed_img->width; j++)
            transformed_img->data[i][j] = init_img->data[i][j];
    }
}


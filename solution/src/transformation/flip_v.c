//
// Created by мак on 12.12.2024.
//

#include <image.h>
#include <stdlib.h>

struct transformation_result flip_v(struct image* init_image, struct image* transformed_img){
    transformed_img->height = init_image->height;
    transformed_img->width = init_image->width;
    transformed_img->data = malloc(transformed_img->height * sizeof(struct pixel*));
    if (transformed_img->data == NULL) return (struct transformation_result){.status=TRANSFORMATION_MALLOC_FAIL, .image=NULL};

    struct pixel* pixel_space = malloc(transformed_img->width * transformed_img->height * sizeof(struct pixel));
    if(pixel_space == NULL) return (struct transformation_result){.status=TRANSFORMATION_MALLOC_FAIL, .image=NULL};

    for (int i = 0; i < transformed_img->height; i++) {
        transformed_img->data[i] = pixel_space + i * transformed_img->width;
    }

    for (int i = 0; i < init_image->height; i++) {
        for (int j = 0; j < init_image->width; j++)
            transformed_img->data[init_image->height - 1 - i][j] = init_image->data[i][j];
    }

    return (struct transformation_result){.status=TRANSFORMATION_OK, .image=transformed_img};
}

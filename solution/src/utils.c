//
// Created by мак on 12.12.2024.
//
#include <stdlib.h>
#include <utils.h>

void free_img_data(struct image* image){
    for (size_t i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
}

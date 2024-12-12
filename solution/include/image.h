//
// Created by мак on 01.12.2024.
//

#ifndef ASSIGNMENT_3_IMAGE_TRANSFORM_IMAGE_H
#define ASSIGNMENT_3_IMAGE_TRANSFORM_IMAGE_H
#include <stdint.h>

struct pixel { uint8_t b,g,r; };
struct image {
    int64_t width, height;
    struct pixel** data;
};

#endif //ASSIGNMENT_3_IMAGE_TRANSFORM_IMAGE_H

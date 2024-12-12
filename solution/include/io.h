//
// Created by мак on 01.12.2024.
//

#ifndef ASSIGNMENT_3_IMAGE_TRANSFORM_IO_H
#define ASSIGNMENT_3_IMAGE_TRANSFORM_IO_H
#include <bmp.h>
#include <image.h>

enum read_status read_img(char* file_path, struct image* img);

enum write_status write_img(char* dest_path, struct image* dest_image);


#endif //ASSIGNMENT_3_IMAGE_TRANSFORM_IO_H

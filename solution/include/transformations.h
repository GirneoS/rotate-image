//
// Created by мак on 12.12.2024.
//

#ifndef IMAGE_TRANSFORM_TRANSFORMATIONS_H
#define IMAGE_TRANSFORM_TRANSFORMATIONS_H

enum transformation_status flip_v(struct image* init_img, struct image* transformed_img);
enum transformation_status flip_h(struct image* init_img, struct image* transformed_img);
enum transformation_status cw_90(struct image* init_img, struct image* transformed_img);
enum transformation_status ccw_90(struct image* init_img, struct image* transformed_img);

#endif //IMAGE_TRANSFORM_TRANSFORMATIONS_H

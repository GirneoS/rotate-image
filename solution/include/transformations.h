//
// Created by мак on 12.12.2024.
//

#ifndef IMAGE_TRANSFORM_TRANSFORMATIONS_H
#define IMAGE_TRANSFORM_TRANSFORMATIONS_H

struct transformation_result flip_v(struct image* init_img, struct image* transformed_img);
struct transformation_result flip_h(struct image* init_img, struct image* transformed_img);
struct transformation_result cw_90(struct image* init_img, struct image* transformed_img);
struct transformation_result ccw_90(struct image* init_img, struct image* transformed_img);

#endif //IMAGE_TRANSFORM_TRANSFORMATIONS_H

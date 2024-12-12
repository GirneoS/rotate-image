//
// Created by мак on 12.12.2024.
//

#ifndef IMAGE_TRANSFORM_TRANSFORMATIONS_H
#define IMAGE_TRANSFORM_TRANSFORMATIONS_H

void flip_v(struct image* init_img, struct image* transformed_img);
void flip_h(struct image* init_img, struct image* transformed_img);
void cw_90(struct image* init_img, struct image* transformed_img);
void ccw_90(struct image* init_img, struct image* transformed_img);
void none(struct image* init_img, struct image* transformed_img);

#endif //IMAGE_TRANSFORM_TRANSFORMATIONS_H

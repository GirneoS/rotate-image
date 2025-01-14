#include "image.h"
#include <io.h>
#include <string.h>
#include <transformations.h>
#include <utils.h>

struct transformation_result transform_image(struct image* init_image, char* transform_mode){
    struct image transformed_image = *init_image;
    struct transformation_result result = {.status = TRANSFORMATION_OK, .image = init_image};

    if (strcmp(transform_mode, "cw90") == 0)
        result = cw_90(init_image, &transformed_image);
    if(strcmp(transform_mode, "ccw90") == 0)
        result = ccw_90(init_image, &transformed_image);
    if (strcmp(transform_mode, "fliph") == 0)
        result = flip_h(init_image, &transformed_image);
    if(strcmp(transform_mode, "flipv") == 0)
        result = flip_v(init_image, &transformed_image);

    return result;
}

int main( int argc, char** argv ) {
    if (argc != 4){
        return 1;
    }
    char* src_path = argv[1];
    char* dest_path = argv[2];
    char* transform_mode = argv[3];

    struct image init_image = {0};
    enum read_status read_result = read_img(src_path, &init_image);
    if(read_result == READ_OPEN_FAIL)
        return 2;
    if(read_result == READ_INVALID_HEADER || read_result == READ_INVALID_BITS || read_result == READ_INVALID_SIGNATURE)
        return 12;
    if(read_result != 0)
        return NOT_ENOUGH_MEMORY;

    struct transformation_result transformationResult = transform_image(&init_image, transform_mode);

    if(transformationResult.status != TRANSFORMATION_OK)
        return transformationResult.status;

    struct image transformed_image = *transformationResult.image;

    enum write_status write_result = write_img(dest_path, &transformed_image);
    if(write_result != WRITE_OK) {
        free_img_data(&transformed_image);
        return write_result;
    }

    free_img_data(&init_image);
    if(strcmp(transform_mode, "none") != 0)
        free_img_data(&transformed_image);

    return 0;
}


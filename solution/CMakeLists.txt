file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)

add_executable(image-transform ${sources}
        include/bmp.h
        include/image.h
        include/utils.h
        include/io.h
        src/bmp.c
        src/io.c
        src/utils.c
        src/transformation/ccw_90.c
        src/transformation/cw_90.c
        src/transformation/flip_h.c
        src/transformation/flip_v.c
        include/transformations.h
        src/transformation/none.c
)
target_include_directories(image-transform PRIVATE src include)

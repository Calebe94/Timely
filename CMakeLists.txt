file(GLOB_RECURSE SOURCES src/*.c)
add_library(timely STATIC ${SOURCES})

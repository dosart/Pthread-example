cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME pthread_wrappers)
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES C)

add_library(${PROJECT_NAME} STATIC pthread_wrappers.c pthread_wrappers.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

set_target_properties(${PROJECT_NAME} PROPERTIES
        C_STANDARD 11
        C_STANDARD_REQUIRED ON)
add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wenum-compare
        -Wfloat-equal
        -Wredundant-decls
        -Wsign-conversion)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
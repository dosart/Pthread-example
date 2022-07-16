cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME counter)
set(THREAD_WRAPPERS_LIB pthread_wrappers)
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES C)

add_executable(${PROJECT_NAME} main.c counter.c)
target_link_libraries(${PROJECT_NAME} ${THREAD_WRAPPERS_LIB})	
set_target_properties(${PROJECT_NAME} PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
     
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

cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME create_thread)
set(THREAD_WRAPPERS_LIB pthread_wrappers)
project(${PROJECT_NAME} VERSION 0.0.2 LANGUAGES C)

 
set(HELLO_THREAD "hello_thread")
add_executable(${HELLO_THREAD} hello_thread.c)
target_link_libraries(${HELLO_THREAD} ${THREAD_WRAPPERS_LIB})	
set_target_properties(${HELLO_THREAD} PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)

set(THREAD_WITH_ARGS "thread_with_args")
add_executable(${THREAD_WITH_ARGS} thread_with_args.c)
target_link_libraries(${THREAD_WITH_ARGS} ${THREAD_WRAPPERS_LIB})	
set_target_properties(${THREAD_WITH_ARGS} PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED ON)
        
        
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

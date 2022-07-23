cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME pthread_examples)
project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES C)

add_subdirectory(create_thread)
add_subdirectory(pthread_wrappers)
add_subdirectory(data_structures)
add_subdirectory(producer_consumer)
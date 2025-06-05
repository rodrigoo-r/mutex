cmake_minimum_required(VERSION 3.12)
project(mutex C)

set(CMAKE_C_STANDARD 11)

add_library(mutex STATIC mutex.c)

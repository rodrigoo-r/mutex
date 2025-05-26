cmake_minimum_required(VERSION 3.30)
project(mutex C)

set(CMAKE_C_STANDARD 11)

add_library(mutex STATIC include/fluent/mutex/mutex.c)

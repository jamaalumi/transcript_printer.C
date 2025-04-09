cmake_minimum_required(VERSION 3.10)
project(transcript_printer C)

set(CMAKE_C_STANDARD 99)

add_executable(transcript_printer main.c parser.c)

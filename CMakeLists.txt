cmake_minimum_required(VERSION 3.20)
project(SaveSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.h)

add_executable(SaveSystem ${SOURCES} "src/ByteWriter.h" "src/ByteWriter.cpp" "src/ByteReader.h" "src/ByteReader.cpp")

if(MSVC)
    target_compile_options(SaveSystem PRIVATE /W4)
endif()
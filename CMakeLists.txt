cmake_minimum_required(VERSION 3.0.0)
project(ExampleClion)

set(CMAKE_CXX_STANDARD 11)

# 声明一个变量SDL2_DIR为SDL2安装路径
set(SDL2_DIR C:/Users/Cripandy/mingw64/x86_64-w64-mingw32)
# 设置要包含的头文件的路径
include_directories(${SDL2_DIR}/include/SDL2)
# 设置要关联的库的路径
link_directories(${SDL2_DIR}/bin)

add_executable(ExampleClion main.c basic.c headfile.h)

target_link_libraries(ExampleClion mingw32 SDL2 SDL2main)
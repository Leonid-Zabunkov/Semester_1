cmake_minimum_required(VERSION 3.10.0)
project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Ex_OP Ex_OP.cpp)

# Применяем настройки к цели Ex_OP, а не к проекту lab3
set_target_properties(Ex_OP PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

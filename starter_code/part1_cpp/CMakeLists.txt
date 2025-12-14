cmake_minimum_required(VERSION 3.15)
project(mixar_uv_unwrap)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)

include_directories(
    ${EIGEN3_INCLUDE_DIR}
    src
)

add_executable(test_unwrap
    src/main.cpp
    src/mesh.cpp
    src/seam_detection.cpp
    src/island_extraction.cpp
    src/lscm.cpp
    src/unwrap.cpp
)

target_link_libraries(test_unwrap Eigen3::Eigen)

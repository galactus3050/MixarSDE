#pragma once
#include <Eigen/Dense>
#include <vector>

struct Face {
    int v[3];
};

struct Mesh {
    std::vector<Eigen::Vector3d> vertices;
    std::vector<Face> faces;
};

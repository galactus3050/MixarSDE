#pragma once
#include "mesh.h"
#include <vector>

std::vector<Eigen::Vector2d> compute_lscm(const Mesh& mesh);

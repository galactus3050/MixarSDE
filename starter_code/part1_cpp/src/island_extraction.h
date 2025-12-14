#pragma once
#include "mesh.h"
#include <vector>
#include <set>

std::vector<std::vector<int>> extract_islands(
    const Mesh& mesh,
    const std::set<std::pair<int,int>>& seams
);

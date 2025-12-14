#pragma once
#include "mesh.h"
#include <set>

std::set<std::pair<int,int>> detect_seams(const Mesh& mesh);

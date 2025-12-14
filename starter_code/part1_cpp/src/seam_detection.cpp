#include "seam_detection.h"
#include <map>
#include <cmath>

static Eigen::Vector3d face_normal(
    const Mesh& m, const Face& f
) {
    auto a = m.vertices[f.v[0]];
    auto b = m.vertices[f.v[1]];
    auto c = m.vertices[f.v[2]];
    return (b - a).cross(c - a).normalized();
}

std::set<std::pair<int,int>> detect_seams(const Mesh& mesh) {
    std::map<std::pair<int,int>, std::vector<int>> edge_faces;

    for (int i = 0; i < mesh.faces.size(); i++) {
        const Face& f = mesh.faces[i];
        for (int e = 0; e < 3; e++) {
            int a = f.v[e];
            int b = f.v[(e+1)%3];
            if (a > b) std::swap(a,b);
            edge_faces[{a,b}].push_back(i);
        }
    }

    std::set<std::pair<int,int>> seams;
    for (auto& it : edge_faces) {
        if (it.second.size() == 1) {
            seams.insert(it.first); // boundary
        } else if (it.second.size() == 2) {
            auto n1 = face_normal(mesh, mesh.faces[it.second[0]]);
            auto n2 = face_normal(mesh, mesh.faces[it.second[1]]);
            double angle = acos(std::clamp(n1.dot(n2), -1.0, 1.0));
            if (angle > M_PI / 3.0)
                seams.insert(it.first);
        }
    }
    return seams;
}

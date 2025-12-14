#include "lscm.h"
#include <Eigen/Sparse>

std::vector<Eigen::Vector2d> compute_lscm(const Mesh& mesh) {
    int n = mesh.vertices.size();
    Eigen::SparseMatrix<double> A(2*n, 2*n);
    Eigen::VectorXd b = Eigen::VectorXd::Zero(2*n);

    for (int i = 0; i < 2*n; i++)
        A.insert(i,i) = 1.0;

    // Anchor vertices
    b(0) = 0; b(1) = 0;
    b(2) = 1; b(3) = 0;

    Eigen::SimplicialLDLT<Eigen::SparseMatrix<double>> solver;
    solver.compute(A);
    Eigen::VectorXd x = solver.solve(b);

    std::vector<Eigen::Vector2d> uv(n);
    for (int i = 0; i < n; i++)
        uv[i] = { x(2*i), x(2*i+1) };

    return uv;
}

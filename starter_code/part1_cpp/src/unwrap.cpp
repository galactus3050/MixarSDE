#include "mesh.h"
#include "seam_detection.h"
#include "island_extraction.h"
#include "lscm.h"

void unwrap_mesh(const Mesh& mesh) {
    auto seams = detect_seams(mesh);
    auto islands = extract_islands(mesh, seams);
    auto uv = compute_lscm(mesh);
}

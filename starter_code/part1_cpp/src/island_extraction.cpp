#include "island_extraction.h"
#include <map>
#include <stack>

std::vector<std::vector<int>> extract_islands(
    const Mesh& mesh,
    const std::set<std::pair<int,int>>& seams
) {
    std::map<int, std::vector<int>> adjacency;

    for (int i = 0; i < mesh.faces.size(); i++) {
        for (int j = i+1; j < mesh.faces.size(); j++) {
            int shared = 0;
            for (int a : mesh.faces[i].v)
                for (int b : mesh.faces[j].v)
                    if (a == b) shared++;

            if (shared >= 2) adjacency[i].push_back(j);
        }
    }

    std::vector<bool> visited(mesh.faces.size(), false);
    std::vector<std::vector<int>> islands;

    for (int i = 0; i < mesh.faces.size(); i++) {
        if (visited[i]) continue;
        std::vector<int> island;
        std::stack<int> st;
        st.push(i);

        while (!st.empty()) {
            int f = st.top(); st.pop();
            if (visited[f]) continue;
            visited[f] = true;
            island.push_back(f);

            for (int n : adjacency[f]) {
                if (!visited[n])
                    st.push(n);
            }
        }
        islands.push_back(island);
    }
    return islands;
}

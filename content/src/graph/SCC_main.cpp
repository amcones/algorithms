/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-10 10:27:54 +0800
 */

#include "graph/SCC.h"

#include <iostream>

int main() {
    Front_Star_Graph g(8), g_r(8);
    std::vector<std::array<int, 3> > edges = {
        {0, 1, 0},
        {1, 2, 0},
        {2, 0, 0},
        {3, 1, 0},
        {3, 2, 0},
        {3, 4, 0},
        {4, 5, 0},
        {5, 6, 0},
        {6, 4, 0},
        {6, 7, 0}
    };

    for (auto eg: edges) {
        g.add(eg[0], eg[1], eg[2]);
        g_r.add(eg[1], eg[0], eg[2]);
    }
    std::cout<<"kosaraju result: \n";
    for (const auto ans = kosaraju(g, g_r); const auto& scc: ans) {
        for (const auto node: scc) {
            std::cout << node << ' ';
        }
        std::cout << std::endl;
    }

    std::cout<<"tarjan result: \n";
    for (const auto ans = tarjan_scc(g); const auto& scc: ans) {
        for (const auto node: scc) {
            std::cout << node << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}

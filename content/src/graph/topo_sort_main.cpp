/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-11 23:15:11 +0800
 */

#include "graph/topo_sort.h"

#include <iostream>

#include "graph/front_star.h"

int main() {
    Front_Star_Graph g(6);
    g.add(0, 1, 3);
    g.add(0, 2, 2);
    g.add(1, 3, 2);
    g.add(1, 4, 3);
    g.add(2, 3, 4);
    g.add(2, 5, 3);
    g.add(3, 5, 2);
    g.add(4, 5, 1);
    std::vector<int> in = {0, 1, 1, 2, 1, 3};
    std::vector<int> res;
    kahn(g, res, in);
    std::cout << "Kahn result: \n";
    for (const auto p: res) {
        std::cout << p << ' ';
    }
    std::cout << std::endl;
    res.clear();
    topo(g, res);
    std::cout << "DFS result: \n";
    for (const auto p: res) {
        std::cout << p << ' ';
    }
    std::cout << std::endl;
}

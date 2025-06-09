/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-10 00:24:26 +0800
 */

#include <iostream>

#include "graph/front_star.h"
#include "graph/MST.h"

int main() {
    Front_Star_Graph g(6);
    g.add_bi(0, 1, 6);
    g.add_bi(0, 2, 1);
    g.add_bi(0, 3, 5);
    g.add_bi(1, 2, 5);
    g.add_bi(1, 4, 3);
    g.add_bi(2, 3, 5);
    g.add_bi(2, 4, 6);
    g.add_bi(2, 5, 4);
    g.add_bi(3, 5, 2);
    g.add_bi(4, 5, 6);
    std::cout << "prim result: " << prim(g, 0) << std::endl;
    std::cout << "kruskal result: " << kruskal(g) << std::endl;
}

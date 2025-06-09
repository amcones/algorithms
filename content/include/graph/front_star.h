/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-09 21:11:04 +0800
 */

#ifndef FRONT_STAR_H
#define FRONT_STAR_H
#include <vector>

struct Edge {
    int to, next, weight;
};

struct Graph {
    std::vector<int> head;
    std::vector<Edge> edge;
    int tot;

    explicit Graph(const int n, const int m): head(n), edge(m), tot(0) {
    }

    void add(const int u, const int v, const int w) {
        edge[tot] = {v, head[u], w};
        head[u] = tot++;
    }
};

#endif //FRONT_STAR_H

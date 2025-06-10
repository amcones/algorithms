/*
 * Author: uli
 * License: MIT
 * Description: 链式前向星，数组模拟邻接表
 * Time: 2025-06-10 00:19:13 +0800
 */

#ifndef FRONT_STAR_H
#define FRONT_STAR_H
#include <vector>

struct Edge {
    int from, to, next, weight;
};

struct Front_Star_Graph {
    std::vector<int> head;
    std::vector<Edge> edge;
    std::vector<int> vis;
    int cnt;

    explicit Front_Star_Graph(const int n): head(n, -1), vis(n), cnt(n) {
    }

    /**
     * 有向图加边
     */
    void add(const int u, const int v, const int w) {
        edge.push_back({u, v, head[u], w});
        head[u] = edge.size() - 1;
    }

    /**
     * 无向图加边
     */
    void add_bi(const int u, const int v, const int w) {
        add(u, v, w);
        add(v, u, w);
    }
};

#endif //FRONT_STAR_H

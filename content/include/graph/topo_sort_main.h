/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-11 22:50:50 +0800
 */

#ifndef TOP_SORT_H
#define TOP_SORT_H
#include <queue>

#include "front_star.h"

inline bool kahn(Front_Star_Graph &g, std::vector<int> &res, std::vector<int> in) {
    auto &[head,edge,_,n] = g;
    std::queue<int> q;
    for (auto i: in) {
        if (i == 0)q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int i = head[u]; ~i; i = edge[i].next) {
            if (const int v = edge[i].to; --in[v] == 0) q.push(v);
        }
    }
    return res.size() == n;
}

inline bool topo(Front_Star_Graph &g, std::vector<int> &res) {
    auto &[head,edge,vis,n] = g;
    std::function<bool(int)> dfs = [&](const int u) -> bool {
        vis[u] = 1;
        for (int i = head[u]; ~i; i = edge[i].next) {
            const int v = edge[i].to;
            if (vis[v] == 1) return false;
            if (!vis[v] && !dfs(v)) return false;
        }
        vis[u] = 2;
        res.push_back(u);
        return true;
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i] && !dfs(i)) {
            return false;
        }
    }
    std::ranges::reverse(res);
    return true;
}

#endif //TOP_SORT_H

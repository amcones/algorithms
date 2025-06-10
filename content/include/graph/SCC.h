/*
 * Author: uli
 * License: MIT
 * Description: 两种强连通分量，复杂度都是 O(V+E)
 * Time: 2025-06-10 09:40:48 +0800
 */

#ifndef SCC_H
#define SCC_H
#include <stack>

#include "front_star.h"

struct Front_Star_Graph;

/**
 * 两次 dfs，第一次走到每个 SCC 的最深处，第二次从每个 SCC 走出来，无法到达其它 SCC
 * O(V+E)
 * @param g 正图
 * @param g_r 反图
 * @return 所有 SCC
 */
inline std::vector<std::vector<int> > kosaraju(Front_Star_Graph &g, Front_Star_Graph &g_r) {
    auto &[head1,edge1,vis1,n] = g;
    auto &[head2,edge2,vis2,_] = g_r;

    std::stack<int> stk;
    std::vector<std::vector<int> > scc_s;
    std::function<void(int)> dfs1 = [&](const int u) {
        vis1[u] = true;
        for (int i = head1[u]; ~i; i = edge1[i].next) {
            const int v = edge1[i].to;
            if (!vis1[v]) dfs1(v);
        }
        stk.push(u);
    };
    for (int i = 0; i < n; i++) {
        if (!vis1[i]) dfs1(i);
    }
    std::function<void(int, std::vector<int> &)> dfs2 = [&](const int u, std::vector<int> &scc) {
        vis2[u] = true;
        scc.push_back(u);
        for (int i = head2[u]; ~i; i = edge2[i].next) {
            if (const int v = edge2[i].to; !vis2[v]) dfs2(v, scc);
        }
    };
    while (!stk.empty()) {
        const int u = stk.top();
        stk.pop();
        if (!vis2[u]) {
            std::vector<int> scc;
            dfs2(u, scc);
            scc_s.push_back(move(scc));
        }
    }
    return scc_s;
}

/**
 * 一次 dfs，根据 dfs 序判断是否 SCC，可以在线
 * 亦可用于缩点，找割点、桥
 * @param g 有向图
 * @return 所有 SCC
 */
inline std::vector<std::vector<int> > tarjan_scc(Front_Star_Graph &g) {
    auto &[head,edge,vis,n] = g;
    std::vector<int> dfn(n), low(n), in_stk(n);
    std::stack<int> stk;
    std::vector<std::vector<int> > scc_s;
    int time = 0;

    std::function<void(int)> dfs = [&](const int u) {
        dfn[u] = low[u] = ++time;
        stk.push(u);
        in_stk[u] = true;

        for (int i = head[u]; ~i; i = edge[i].next) {
            const int v = edge[i].to;
            if (!dfn[v]) {
                dfs(v);
                low[u] = std::min(low[u], low[v]);
            } else if (in_stk[v]) {
                low[u] = dfn[v];
            }
        }

        if (dfn[u] == low[u]) {
            std::vector<int> scc;
            int v;
            do {
                v = stk.top();
                stk.pop();
                scc.push_back(v);
                in_stk[v] = false;
            } while (u != v);
            scc_s.push_back(std::move(scc));
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) dfs(i);
    }
    return scc_s;
}

#endif //SCC_H

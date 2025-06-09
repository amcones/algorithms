/*
 * Author: uli
 * License: MIT
 * Description: 最小生成树，顶点编号从 0 开始
 * Time: 2025-06-10 00:15:36 +0800
 */

#ifndef MST_H
#define MST_H
#include <queue>

#include "front_star.h"
#include "union_find_set.h"

constexpr int INF = 0x3f3f3f3f;


/**
 * Prim 算法，选点
 * O(nlog(n))
 * @param g 图
 * @param s 起始点
 * @return MST 的权值总和
 */
inline int prim(Front_Star_Graph &g, const int s) {
    const auto n = g.head.size();
    std::vector dis(n, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<> > pq;
    int tot = 0;
    dis[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        const int u = pq.top().second;
        pq.pop();
        if (g.vis[u]) continue;
        g.vis[u] = true;
        tot += dis[u];
        for (int i = g.head[u]; ~i; i = g.edge[i].next) {
            const int v = g.edge[i].to, w = g.edge[i].weight;
            if (!g.vis[v] && w < dis[v]) {
                dis[v] = w;
                pq.emplace(dis[v], v);
            }
        }
    }
    for (const auto v: g.vis) {
        if (!v) return -1;
    }
    return tot;
}

/**
 * Kruskal 算法，选边
 * 由于要排序，为了不修改原图，传原图的拷贝
 * O(mlog(m))
 * @param g 图
 * @return MST 的权值总和
 */
inline int kruskal(Front_Star_Graph g) {
    const auto n = g.head.size();
    union_find_set ufs(n);
    std::ranges::sort(g.edge, [](const Edge &a, const Edge &b) { return a.weight < b.weight; });
    int cnt = 0, tot = 0;
    for (const auto e: g.edge) {
        const int fu = ufs.find(e.from), fv = ufs.find(e.to);
        if (fu != fv) {
            tot += e.weight;
            ufs.comb(fu, fv);
            cnt++;
        }
        if (cnt == n - 1)break;
    }
    return cnt == n - 1 ? tot : -1;
}

#endif //MST_H

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
    auto &[head,edge,vis,n] = g;
    std::vector dis(n, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<> > pq;
    int tot = 0;
    dis[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        const int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        tot += dis[u];
        for (int i = head[u]; ~i; i = edge[i].next) {
            const int v = edge[i].to, w = edge[i].weight;
            if (!vis[v] && w < dis[v]) {
                dis[v] = w;
                pq.emplace(dis[v], v);
            }
        }
    }
    for (const auto v: vis) {
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
    auto &[head,edge,vis,n] = g;
    union_find_set ufs(n);
    std::ranges::sort(edge, [](const Edge &a, const Edge &b) { return a.weight < b.weight; });
    int cnt = 0, tot = 0;
    for (const auto e: edge) {
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

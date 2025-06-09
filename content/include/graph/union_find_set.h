/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-10 00:31:52 +0800
 */

#ifndef UNION_FIND_SET_H
#define UNION_FIND_SET_H
#include <numeric>
#include <vector>

struct union_find_set {
    std::vector<int> fa;
    std::vector<int> rank;

    explicit union_find_set(const int n): fa(n), rank(n) {
        std::iota(fa.begin(), fa.end(), 0);
    }

    int find(const int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    void comb(const int x, const int y) {
        const int fx = find(x), fy = find(y);
        if (rank[fx] <= rank[fy]) {
            fa[fx] = fy;
        } else {
            fa[fy] = fx;
        }
        if (rank[fx] == rank[fy] && fx != fy) {
            rank[fy]++;
        }
    }
};

#endif //UNION_FIND_SET_H

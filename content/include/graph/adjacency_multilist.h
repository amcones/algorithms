/*
 * Author: uli
 * License: MIT
 * Description:
 * Time: 2025-06-10 00:24:27 +0800
 */

#ifndef ADJACENCY_MULTILIST_H
#define ADJACENCY_MULTILIST_H
#include <string>
#include <vector>

struct EdgeNode {
    int i_vex, j_vex;
    EdgeNode *i_next, *j_next;
    int weight;
};

struct VexNode {
    std::string data;
    EdgeNode *firstEdge;
};

inline void add(const int i, const int j, const int w, std::vector<VexNode> &vertices) {
    const auto edge = new EdgeNode;
    edge->i_vex = i;
    edge->j_vex = j;
    edge->weight = w;

    // 挂到 i 的邻接表
    edge->i_next = vertices[i].firstEdge;
    vertices[i].firstEdge = edge;

    // 挂到 j 的邻接表
    edge->j_next = vertices[j].firstEdge;
    vertices[j].firstEdge = edge;
}


#endif //ADJACENCY_MULTILIST_H

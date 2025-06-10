# 最小生成树（MST）

## 概念

### 最小生成树

生成树是指在一张 $n$ 个顶点的图中选出 $n-1$ 条边，使得图变为一棵树。最小生成树是一张图的所有生成树中边权值总和 **最小** 的生成树。

最小生成树 **不是** 唯一的。

## 算法

常用算法有两种：Prim 和 Kruskal，查看 [实现](../../content/include/graph/MST.h)。

- Prim：选点。适合稠密图。每次找到距离 MST 最小的一点加入，可用堆维护。
- Kruskal：选边。适合稀疏图。从小到大加入边，过程是维护一个森林，查询两个节点是否在同一棵树，连接两棵树。使用并查集维护。

都属于 **贪心**。

## 示例

[Kruskal](https://leetcode.cn/problems/connecting-cities-with-minimum-cost/submissions/635845978)
# 强连通分量（SCC）

## 概念

### SCC

强连通分量是指图中的一个子集，其中 **任意** 两个顶点 **互相** 可达。

容易发现此条件在有向图中更有研究意义，所以经常用在有向图中。可用于 **缩点** 并进行下一步算法。

### 割点与桥

参考 [割](https://oi-wiki.org/graph/concept/#%E5%89%B2)。

## 算法

常用算法有两种：Kosaraju 和 Tarjan，查看 [实现](https://github.com/amcones/algorithms/tree/main/content/include/graph/SCC.h)。

- Kosaraju：两次 dfs，一次在正图，一次在反图（即将原图所有边反转）。第一次 dfs 可以找到所有 SCC 最深处的顶点，第二次 dfs 从这些点开始向外搜索。由强连通分量的定义可知，两个强连通分量间 **没有** 或 **仅有一个方向** 可以通过，因此第二次 dfs 能够搜索出所有的 SCC。
- Tarjan：一次 dfs，不需要建反图。利用 dfs 序来找到 SCC。对于每个顶点 $x$，记录其 dfs 序 $dfn[x]$ 与所有可达顶点的 dfs 序最小值 $low[x]$，用一个栈保存已经访问过的节点。当 $dfn[x]=low[x]$ 时，我们找到了一个 SCC 当中第一个被访问的点。此时栈中的所有点都属于该 SCC。此外，Tarjan 还可以在线，求割点、桥。

## 示例

[Tarjan 求割边](https://leetcode.cn/problems/critical-connections-in-a-network/submissions/635836054/)
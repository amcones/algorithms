# [拓扑排序](https://github.com/amcones/algorithms/tree/main/content/include/graph/topo_sort.h)

1. 从图中选择一个入度为 0 的点
2. 删除该点及其所有出边

删除的顺序就是拓扑序。可以用 BFS 或 DFS 实现，其中 BFS 实现叫做 Kahn 算法。

## AOV 网与 AOE 网 

1. AOV（Activity on vertex），即顶点表示活动。DAG。
2. AOE（Activity on edge），即边表示活动。带权 DAG。
   1. 关键路径：从源点到汇点的所有路径中最长的路径。
   2. 关键活动：关键路径上的活动。设活动 $a_i$ 的最早开始时间为 $e_i$，最晚开始时间为 $l_i$，称差额 $d_i=l_i-e_i$。如果 $d_i = 0$，则 $a_i$ 是关键活动。
   3. 从源点按拓扑序求 $e_i$，从汇点按逆拓扑序求 $l_i$。把握住依赖关系求解。
   4. 关键路径可能不唯一，只有加快所有关键路径上的所有关键活动才能缩短工期。

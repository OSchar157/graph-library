#include "graph_algs.h"

template <typename T>
Graph<T> DFS(Graph<T> graph, Vertex<T> *start)
{
    Graph<T> dfs_result_graph;
    DFS_helper(graph, start, dfs_result_graph);
    return dfs_result_graph;
}

template <typename T>
void DFS_helper(Graph<T> G, Vertex<T> *curr, Graph<T> dfs_result_graph)
{
    std::pair<float, Vertex<T> *> neighbors = G[curr];
    for(neighbor)
}
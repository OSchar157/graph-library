#include "graph/graph.h"
#include "graph_algs/graph_algs.h"

#include <iostream>
using namespace std;

int main()
{
    Graph<int> graph;
    Vertex<int>* vert1 = graph.addVertex(1);
    Vertex<int>* vert2 = graph.addVertex(2);
    Vertex<int>* vert3 = graph.addVertex(3);
    Vertex<int>* vert4 = graph.addVertex(4);
    Vertex<int>* vert5 = graph.addVertex(5);

    graph.addEdge(vert1, vert3, 2);
    graph.addEdge(vert3, vert4, 5);
    graph.addEdge(vert4, vert5, 1);

    for(Vertex<int>* vert : graph.getVertices())
    {
        cout << vert->get_value();
    }

    cout << endl;

    Graph<int> dfs_result = GraphAlgorithms<int>::DFS(graph, vert1);

    for(Vertex<int>* vert : dfs_result.getVertices())
    {
        cout << vert->get_value() << endl;
    }
}
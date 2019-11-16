#pragma once

#include "Graph.hpp"

struct Neighbour { int vertex; int cost; };

using AdjacencyList = std::vector<std::vector<Neigbour>>;

class ListGraph : public Graph
{
    AdjacencyList adjacency_;
    void initializeAdjacency();
    void randomizeEdges(std::vector<Edge>& possibleEdges, int edgesNumber);

public:

    ListGraph(int vertexNumber, int begin);
    ListGraph() = default;
    void addVertex(int vertex, int neighbour, int pathCost);
    void dijkstra();
    void bellmanFord();
};

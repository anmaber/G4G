#pragma once

#include <vector>
#include <map>
#include <string>

struct Edge
{
    int vertex;
    int cost;

    Edge(int v,int c)
        : vertex(v),
          cost(c)
    {}
};

bool operator>(Edge const& x, Edge const& y)
{
    return x.cost > y.cost;
}

class Graph
{

protected:

    int vertexNumber_;
    int begin_;
    std::vector<int> previous_;
    std::vector<int> distances_;

    std::string getDistanceAndPreviousOnes(int vertex);
    virtual void initializeAdjacency() = 0;
    virtual void randomizeEdges(std::vector<Edge>& possibleEdges, int edgesNumber) = 0;

public:

    Graph(int vertexNumber, int begin);
    Graph() = default;
    void print();
    virtual void addVertex(int vertex, int neighbour, int pathCost) = 0;
    virtual void dijkstra() = 0;
    virtual void bellmanFord() = 0;
    void saveToFile(const std::string& fileName);
    void GenerateRandom(int size, double density);

    virtual ~Graph(){}
};

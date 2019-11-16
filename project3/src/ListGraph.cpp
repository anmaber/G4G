#include "ListGraph.hpp"

#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>

ListGraph::ListGraph(int vertexNumber, int begin)
    : Graph(vertexNumber,begin)
{
    adjacency_.resize(vertexNumber);
}

void ListGraph::addVertex(int vertex, int neighbour, int pathCost)
{
    adjacency_[vertex].emplace_back(Neighbour(neighbour,pathCost));
    adjacency_[neighbour].emplace_back(Neighbour(vertex,pathCost));
}

using EdgeVector = std::vector<Neighbour>;


void ListGraph::dijkstra()
{
    std::priority_queue<Neighbour,EdgeVector,std::greater<Neighbour>> costVertexPq;

int begin = begin_;
    costVertexPq.push(Neighbour(0, begin));
    distances_[begin_] = 0;

    while(!costVertexPq.empty())
    {
        int smallestCost = costVertexPq.top().cost;
        costVertexPq.pop();

        if(!adjacency_[smallestCost].empty())
        {
            for(const auto& neighbour : adjacency_[smallestCost])
            {
 //               int vertex = neighbour.first;
   //             int cost = neighbour.second;

                if (distances_[neighbour.vertex] > distances_[smallestCost] + neighbour.cost)
                {
                    distances_[neighbour.vertex] = distances_[smallestCost] + neighbour.cost;
                    costVertexPq.push(Neighbour(distances_[neighbour.vertex], neighbour.vertex));
                    previous_[neighbour.vertex] = smallestCost;
                }
            }
        }
    }
}

void ListGraph::bellmanFord()
{
    distances_[begin_] = 0;

    for (int i = 0; i < vertexNumber_-1; ++i)
    {
        for (int j = 0; j < vertexNumber_; ++j)
        {
            if(!adjacency_[j].empty())
            {
                for (auto& n : adjacency_[j])
                {

                    if (distances_[n.first] > n.second + distances_[j] && distances_[j]!=INT_MAX)
                    {
                        distances_[n.first] = n.second + distances_[j];
                        previous_[n.first] = j;
                    }
                }
            }
        }
    }
}


void ListGraph::initializeAdjacency()
{
    if(!adjacency_.empty()) adjacency_.clear();

    adjacency_.resize(vertexNumber_);
}

void ListGraph::randomizeEdges(std::vector<Edge>& possibleEdges, int edgesNumber)
{
    for (int i = 0; i < edgesNumber; ++i)
    {
        int cost = std::rand() % 50 +1;
        int edgeIndex = std::rand() % possibleEdges.size();

        Edge e = possibleEdges.at(edgeIndex);
        auto toRemove = possibleEdges.begin()+edgeIndex;
        possibleEdges.erase(toRemove);
        adjacency_[e.first].emplace_back(std::make_pair(e.second,cost));
        adjacency_[e.second].emplace_back(std::make_pair(e.first,cost));
    }


}

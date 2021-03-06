#pragma once

#include <vector>
#include <list>
#include <limits>
#include <iostream>

//Reference for designing some of the interfaces:
//https://networkx.org/documentation/latest/tutorial.html

class GraphFixedSize
{
public:
    GraphFixedSize(size_t s)
        :
        m_adjacencyList(s),
        m_color(s, 'w'),
        m_distance(s, std::numeric_limits<uint32_t>::max()),
        m_predecessor(s, std::numeric_limits<uint32_t>::max()),
        m_graphTraversalIsStale(true),
        m_sourceNodeForBFS(std::numeric_limits<uint32_t>::max())
    {}

    void setNeighborsOfANode(const uint32_t node, const std::vector<uint32_t>& neighbors);

    uint32_t shortestPathBFS(const uint32_t source, const uint32_t dest);
    void printDistanceToAllNodesBFS(const uint32_t source);
    void printPredecessorOfAllNodesBFS(const uint32_t source);
    void printGraph();

    //int shortestPathDFS(const int source, const int dest) const;
    //void printDistanceToAllNodesDFS(const int source) const;
    //void printPredecessorOfAllNodesDFS(const int source) const;

private:
    void runBFS(const uint32_t source);
    void resetColorPrdecessorDistance();
    //void runDFS(const int source);

    std::vector<std::vector<uint32_t>> m_adjacencyList;
    std::vector<char> m_color;
    std::vector<uint32_t> m_distance;
    std::vector<uint32_t> m_predecessor;
    bool m_graphTraversalIsStale;
    uint32_t m_sourceNodeForBFS;
};

/*
template <typename T>
class GraphVariableSize
{
    
    uint32_t shortestPathBFS(const T& source, const T& dest) const;

private:
    std::unordered_map<T, std::unordered_set<T>> m_adjacencyList;
}
*/

void GraphFixedSize::setNeighborsOfANode(const uint32_t node, const std::vector<uint32_t>& neighbors)
{
    if( m_adjacencyList[node] != neighbors)
    {
        m_adjacencyList[node] = neighbors;
    }
    m_graphTraversalIsStale = true;
}

uint32_t GraphFixedSize::shortestPathBFS(const uint32_t source, const uint32_t dest)
{
    runBFS(source);
    return m_distance[dest];
}

void GraphFixedSize::printDistanceToAllNodesBFS(const uint32_t source)
{
    runBFS(source);

    std::cout << "Distance from the source node, " << source << ", to all other nodes" << std::endl;

    for (auto d : m_distance)
    {
        std::cout << " " << d;
    }

    std::cout << std::endl;
}

void GraphFixedSize::printPredecessorOfAllNodesBFS(const uint32_t source)
{
    runBFS(source);

    std::cout << "Predecessor for all nodes when the source node is " << source << std::endl;

    for (auto p : m_predecessor)
    {
        std::cout << " " << p;
    }

    std::cout << std::endl;
}

void GraphFixedSize::printGraph()
{
    for (int i = 0; i < m_adjacencyList.size(); i++)
    {
        std::cout << i << " ";
        for (auto n : m_adjacencyList[i])
        {
            std::cout << "->" << n; 
        }
        std::cout << std::endl;
    }
}

void GraphFixedSize::resetColorPrdecessorDistance()
{
    for (int i = 0; i < m_color.size(); i++)
    {
        m_color[i] = 'w';
        m_distance[i] = std::numeric_limits<uint32_t>::max(); 
        m_predecessor[i] = std::numeric_limits<uint32_t>::max(); 
    }
}

void GraphFixedSize::runBFS(const uint32_t source)
{
    if (!m_graphTraversalIsStale && m_sourceNodeForBFS == source) return;

    resetColorPrdecessorDistance();

    m_color[source] = 'g';
    m_predecessor[source] = std::numeric_limits<uint32_t>::max();
    m_distance[source] = 0;
    std::list<uint32_t> nodesToBeProcessed(1, source);

    while (!nodesToBeProcessed.empty())
    {
        auto node = nodesToBeProcessed.front();
        nodesToBeProcessed.pop_front();
        for (auto neighbor : m_adjacencyList[node])
        {
            if (m_color[neighbor] == 'w')
            {
                m_color[neighbor] = 'g';
                m_predecessor[neighbor] = node;
                m_distance[neighbor] = m_distance[node] + 1;
                nodesToBeProcessed.push_back(neighbor);
            }
        }
        m_color[node] = 'b';
    }

    m_graphTraversalIsStale = false;
    m_sourceNodeForBFS = source;
}

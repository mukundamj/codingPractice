#pragma once

#include <vector>
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
        m_predecessor(s, std::numeric_limits<uint32_t>::max())
        m_sourceNodeForBFS(std::numeric_limits<uint32_t>::max());
        m_graphTraversalIsStale(true);
    {}

    void setNeighborsOfANode(const int node, const std::vector<int>& neighbors);

    uint32_t shortestPathBFS(const int source, const int dest) const;
    void printDistanceToAllNodesBFS(const int source) const;
    void printPredecessorOfAllNodesBFS(const int source) const;

    //int shortestPathDFS(const int source, const int dest) const;
    //void printDistanceToAllNodesDFS(const int source) const;
    //void printPredecessorOfAllNodesDFS(const int source) const;

private:
    void runBFS(const int source);
    //void runDFS(const int source);

    std::vector<std::vector<uint32_t>> m_adjacencyList;
    std::vector<char> m_color;
    std::vector<uint32_t> m_distance;
    std::vector<uint32_t> m_predecessor;
    bool m_graphTraversalIsStale;
    uint32_t m_sourceNodeForBFS;
}

/*
template <typename T>
class GraphVariableSize
{
    
    int shortestPathBFS(const T& source, const T& dest) const;

private:
    std::unordered_map<T, std::unordered_set<T>> m_adjacencyList;
}
*/

void GraphFixedSize::setNeighborsOfANode(const int node, const std::vector<int>& neighbors)
{
    if (m_adjacencyList[node] != neighbors)
    {
        m_adjacencyList[node] = neighbors;
        m_graphTraversalIsStale = true;
    }
}

uint32_t GraphFixedSize::shortestPathBFS(const int source, const int dest) const
{
    runBFS(source);
    return m_distance[dest];
}

void GraphFixedSize::printDistanceToAllNodesBFS(const int source) const
{
    runBFS(source);

    std::cout << "Distance from the source node, " << source << ", to all other nodes" << std::endl;

    for (d : m_distance)
    {
        std::cout << " " << d;
    }

    std::cout << std::endl;
}

void GraphFixedSize::printPredecessorOfAllNodesBFS(const int source) const
{
    runBFS(source);

    std::cout << "Predecessor for all nodes with the source node " << source << std::endl;

    for (p : m_predecessor)
    {
        std::cout << " " << d;
    }

    std::cout << std::endl;
}

void GraphFixedSize::runBFS(const int source)
{
    if (!m_graphTraversalIsStale && m_sourceNodeForBFS == source) return;

    m_color[source] = 'g';
    m_predecessor[source] = std::numeric_limits<uint32_t>::max();
    m_distance[source] = 0;
    std::list<int> nodesToBeProcessed(1, source);

    while (!nodesToBeProcessed.empty())
    {
        uint32_t node = nodesToBeProcessed.pop_front();
        for (neighbor : m_adjacencyList[node])
        {
            if (m_color[neighbor] == 'w')
            {
                m_color[neighbor] == 'g'
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

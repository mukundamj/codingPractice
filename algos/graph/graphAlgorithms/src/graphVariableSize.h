#pragma once

#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iostream>

//Reference for designing some of the interfaces:
//https://networkx.org/documentation/latest/tutorial.html

template <typename T>
class GraphVariableSize
{
public:
    void setNeighborsOfANode(const T& node, const std::unordered_set<T>& neighbors);

    uint32_t shortestPathBFS(const T& source, const T& dest);
    T predecessorBFS(const T& source, const T& node);
    uint32_t size() const;
    void printGraph() const;

    //int shortestPathDFS(const int source, const int dest) const;

private:
    void runBFS(const T& source);
    //void runDFS(const T source);

    std::unordered_map<T, std::unordered_set<T>> m_adjacencyList;
    std::vector<char> m_color;
    std::vector<uint32_t> m_distance;
    std::vector<T> m_predecessor;
    bool m_graphTraversalIsStale{true};
    T m_sourceNodeForBFS;
};

template <typename T>
void GraphVariableSize<T>::setNeighborsOfANode(const T& node, const std::unordered_set<T>& neighbors)
{
    if( m_adjacencyList[node] != neighbors)
    {
        m_adjacencyList[node] = neighbors;
        m_graphTraversalIsStale = true;
    }
}

template <typename T>
uint32_t GraphVariableSize<T>::shortestPathBFS(const T& source, const T& dest)
{
    runBFS(source);
    return m_distance[dest];
}

template <typename T>
T GraphVariableSize<T>::predecessorBFS(const T& source, const T& node)
{
    runBFS(source);
    return m_predecessor[node];
}

template <typename T>
uint32_t GraphVariableSize<T>::size() const
{
    return m_adjacencyList.size();
}

template <typename T>
void GraphVariableSize<T>::printGraph() const
{
    std::cout << "\n################### Graph nodes represented as adjacency list ##################\n";
    for (auto it = m_adjacencyList.cbegin(); it != m_adjacencyList.cend(); it++)
    {
        std::cout << it->first;
        for (auto it2 = (it->second).cbegin(); it2 != (it->second).cend(); it2++)
        {
            std::cout << "->" << *it2;
        }
        std::cout << std::endl;
    }
    std::cout << "\n################################################################################\n";
}

template <typename T>
void GraphVariableSize<T>::runBFS(const T& source)
{
    if (!m_graphTraversalIsStale && m_sourceNodeForBFS == source) return;

    std::vector<char> color(size(), 'w');
    std::vector<uint32_t> distance(size(), std::numeric_limits<uint32_t>::max());
    std::vector<T> predecessor(size());

    color[source] = 'g';
    distance[source] = 0;
    std::list<T> nodesToBeProcessed(1, source);

    while (!nodesToBeProcessed.empty())
    {
        auto node = nodesToBeProcessed.front();
        nodesToBeProcessed.pop_front();
        for (auto neighbor : m_adjacencyList[node])
        {
            if (color[neighbor] == 'w')
            {
                color[neighbor] = 'g';
                predecessor[neighbor] = node;
                distance[neighbor] = distance[node] + 1;
                nodesToBeProcessed.push_back(neighbor);
            }
        }
        color[node] = 'b';
    }

    m_color = std::move(color);
    m_distance = std::move(distance);
    m_predecessor = std::move(predecessor);
    m_sourceNodeForBFS = source;
    m_graphTraversalIsStale = false;
}

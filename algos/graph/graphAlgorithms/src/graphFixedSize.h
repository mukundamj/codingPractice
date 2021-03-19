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
        m_bfsAdjacencyList(s),
        m_bfsColor(s, 'w'),
        m_bfsDistance(s, std::numeric_limits<uint32_t>::max()),
        m_bfsPredecessor(s, std::numeric_limits<uint32_t>::max()),
        m_bfsGraphTraversalIsStale(true),
        m_bfsSourceNode(std::numeric_limits<uint32_t>::max())
    {}

    void setNeighborsOfANode(const uint32_t node, const std::vector<uint32_t>& neighbors);

    uint32_t shortestPathBFS(const uint32_t source, const uint32_t dest);
    uint32_t predecessorBFS(const uint32_t source, const uint32_t node);

    uint32_t shortestPathDFS(const uint32_t source, const uint32_t dest);
    uint32_t predecessorDFS(const uint32_t source, const uint32_t node);

    uint32_t size() const;
    void printGraph();

private:
    void runBFS(const uint32_t source);
    void resetBfsColorPrdecessorDistance();
    void runDFS(const int source);

    std::vector<std::vector<uint32_t>> m_bfsAdjacencyList;
    std::vector<char> m_bfsColor;
    std::vector<uint32_t> m_bfsDistance;
    std::vector<uint32_t> m_bfsPredecessor;
    bool m_bfsGraphTraversalIsStale;
    uint32_t m_bfsSourceNode;
};

void GraphFixedSize::setNeighborsOfANode(const uint32_t node, const std::vector<uint32_t>& neighbors)
{
    if( m_bfsAdjacencyList[node] != neighbors)
    {
        m_bfsAdjacencyList[node] = neighbors;
        m_bfsGraphTraversalIsStale = true;
    }
}

uint32_t GraphFixedSize::shortestPathBFS(const uint32_t source, const uint32_t dest)
{
    runBFS(source);
    return m_bfsDistance[dest];
}

uint32_t GraphFixedSize::predecessorBFS(const uint32_t source, const uint32_t node)
{
    runBFS(source);
    return m_bfsPredecessor[node];
}

uint32_t GraphFixedSize::size() const
{
    return m_bfsAdjacencyList.size();
}

void GraphFixedSize::printGraph()
{
    std::cout << "\n################### Graph nodes represented as adjacency list ##################\n";
    for (int i = 0; i < m_bfsAdjacencyList.size(); i++)
    {
        std::cout << i;
        for (auto n : m_bfsAdjacencyList[i])
        {
            std::cout << "->" << n; 
        }
        std::cout << std::endl;
    }
    std::cout << "\n################################################################################\n";
}

void GraphFixedSize::resetBfsColorPrdecessorDistance()
{
    for (int i = 0; i < m_bfsColor.size(); i++)
    {
        m_bfsColor[i] = 'w';
        m_bfsDistance[i] = std::numeric_limits<uint32_t>::max(); 
        m_bfsPredecessor[i] = std::numeric_limits<uint32_t>::max(); 
    }
}

/*
 Analysis for graph G(V, E), V is number of nodes and E is number of edges.
 The operations of enqueuing and dequeuing take O(1) time, and so the total
 time devoted to queue operations is O(V). Because the procedure scans the
 adjacency list of each vertex only when the vertex is dequeued, it scans
 each adjacency list at most once. Since the sum of the lengths of all the
 adjacency lists is O(E), the total time spent in scanning adjacency lists
 is O(E). The overhead for initialization is O(V), and thus the total
 running time of the BFS procedure is O(V + E).
*/
void GraphFixedSize::runBFS(const uint32_t source)
{
    if (!m_bfsGraphTraversalIsStale && m_bfsSourceNode == source) return;

    resetBfsColorPrdecessorDistance();

    m_bfsColor[source] = 'g';
    m_bfsPredecessor[source] = std::numeric_limits<uint32_t>::max();
    m_bfsDistance[source] = 0;
    std::list<uint32_t> nodesToBeProcessed(1, source);

    while (!nodesToBeProcessed.empty())
    {
        auto node = nodesToBeProcessed.front();
        nodesToBeProcessed.pop_front();
        for (auto neighbor : m_bfsAdjacencyList[node])
        {
            if (m_bfsColor[neighbor] == 'w')
            {
                m_bfsColor[neighbor] = 'g';
                m_bfsPredecessor[neighbor] = node;
                m_bfsDistance[neighbor] = m_bfsDistance[node] + 1;
                nodesToBeProcessed.push_back(neighbor);
            }
        }
        m_bfsColor[node] = 'b';
    }

    m_bfsSourceNode = source;
    m_bfsGraphTraversalIsStale = false;
}



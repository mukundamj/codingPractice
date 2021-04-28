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
        m_bfsColor(s, 'w'),
        m_bfsDistance(s, std::numeric_limits<uint32_t>::max()),
        m_bfsPredecessor(s, std::numeric_limits<uint32_t>::max()),
        m_bfsGraphTraversalIsStale(true),
        m_bfsSourceNode(std::numeric_limits<uint32_t>::max()),
        m_dfsColor(s, 'w'),
        m_dfsPredecessor(s, std::numeric_limits<uint32_t>::max()),
        m_dfsTime(0),
        m_dfsGraphTraversalIsStale(true)
    {}

    void setNeighborsOfANode(const uint32_t node, const std::vector<uint32_t>& neighbors);

    uint32_t shortestPathBFS(const uint32_t source, const uint32_t dest);
    uint32_t predecessorBFS(const uint32_t source, const uint32_t node);

    uint32_t predecessorDFS(const uint32_t node);

    uint32_t size() const;
    void printGraph();

private:
    std::vector<std::vector<uint32_t>> m_adjacencyList;

    void BFS(const uint32_t source);
    void resetBfsColorPredecessorDistance();

    std::vector<char> m_bfsColor;
    std::vector<uint32_t> m_bfsDistance;
    std::vector<uint32_t> m_bfsPredecessor;
    bool m_bfsGraphTraversalIsStale;
    uint32_t m_bfsSourceNode;

    void DFS();
    void DFSVisit(const uint32_t s);
    void resetDfsColorPredecessorTime();
    std::vector<char> m_dfsColor;
    std::vector<uint32_t> m_dfsPredecessor;
    uint32_t m_dfsTime;
    bool m_dfsGraphTraversalIsStale;
    /*
        While running DFS algorithm each node will have a start and
        end time. m_dfsNodeDiscoveryAndFinishTime[n].first will represent the node
        discovery time and m_dfsNodeDiscoveryAndFinishTime[n].second will represent
        the finish time.
    */
    std::vector<std::pair<uint32_t, uint32_t>> m_dfsNodeDiscoveryAndFinishTime;

};

void GraphFixedSize::setNeighborsOfANode(const uint32_t node, const std::vector<uint32_t>& neighbors)
{
    if( m_adjacencyList[node] != neighbors)
    {
        m_adjacencyList[node] = neighbors;
        m_bfsGraphTraversalIsStale = true;
        m_dfsGraphTraversalIsStale = true;
    }
}

uint32_t GraphFixedSize::shortestPathBFS(const uint32_t source, const uint32_t dest)
{
    BFS(source);
    return m_bfsDistance[dest];
}

uint32_t GraphFixedSize::predecessorBFS(const uint32_t source, const uint32_t node)
{
    BFS(source);
    return m_bfsPredecessor[node];
}

uint32_t GraphFixedSize::predecessorDFS(const uint32_t node)
{
    DFS();
    return m_dfsPredecessor[node];
}

uint32_t GraphFixedSize::size() const
{
    return m_adjacencyList.size();
}

void GraphFixedSize::printGraph()
{
    std::cout << "\n################### Graph nodes represented as adjacency list ##################\n";
    for (int i = 0; i < m_adjacencyList.size(); i++)
    {
        std::cout << i;
        for (auto n : m_adjacencyList[i])
        {
            std::cout << "->" << n; 
        }
        std::cout << std::endl;
    }
    std::cout << "\n################################################################################\n";
}

void GraphFixedSize::resetBfsColorPredecessorDistance()
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
void GraphFixedSize::BFS(const uint32_t source)
{
    if (!m_bfsGraphTraversalIsStale && m_bfsSourceNode == source) return;

    resetBfsColorPredecessorDistance();

    m_bfsColor[source] = 'g';
    m_bfsPredecessor[source] = std::numeric_limits<uint32_t>::max();
    m_bfsDistance[source] = 0;
    std::list<uint32_t> nodesToBeProcessed(1, source);

    while (!nodesToBeProcessed.empty())
    {
        auto node = nodesToBeProcessed.front();
        nodesToBeProcessed.pop_front();
        for (auto neighbor : m_adjacencyList[node])
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

void GraphFixedSize::resetDfsColorPredecessorTime()
{
    for (uint32_t i = 0; i < m_dfsColor.size(); i++)
    {
        m_dfsColor[i] = 'w';
        m_dfsPredecessor[i] = std::numeric_limits<uint32_t>::max();
    }

    m_dfsTime = 0;
}

void GraphFixedSize::DFS()
{
    if (!m_dfsGraphTraversalIsStale) return;

    resetDfsColorPredecessorTime();

    for (uint32_t i = 0; i < m_adjacencyList.size(); i++)
    {
        if (m_dfsColor[i] == 'w')
        {
            DFSVisit(i);
        }
    }

    m_dfsGraphTraversalIsStale = false;
}

void GraphFixedSize::DFSVisit(const uint32_t s)
{
    m_dfsTime += 1;
    m_dfsNodeDiscoveryAndFinishTime[s].first = m_dfsTime;
    m_dfsColor[s] = 'g';

    for (auto neighbor : m_adjacencyList[s])
    {
        if (m_dfsColor[neighbor] == 'w')
        {
            m_dfsPredecessor[neighbor] = s; 
            DFSVisit(neighbor);
        }
    }

    m_dfsColor[s] = 'b';
    m_dfsTime += 1;
    m_dfsNodeDiscoveryAndFinishTime[s].second = m_dfsTime;
}

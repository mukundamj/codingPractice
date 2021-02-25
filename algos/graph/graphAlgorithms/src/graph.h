#pragma once

#include <vector>

Refer to interfaces in the below link
https://github.com/networkx/networkx
class Graph
{
    struct GaphNode
    {
        GraphNode(const uint8_t k) :
            //The maximum key value is limited to 0xFE because the default
            //predecessor is set as 0xFF
            key(k == 0xFF ? 0xFE : k),
            distance(0xFF),
            predecessor(0xFF),
            color('b')
        {}
        uint8_t key;
        uint8_t distance;
        uint8_t predecessor;
        char color;
    }

    Graph(int no    

private:
    std::vector<std::vector<GraphNode>> m_adjacencyList;
}

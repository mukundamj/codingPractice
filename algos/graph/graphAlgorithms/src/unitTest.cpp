#include <vector>
#include <iostream>
#include "graph.h"

int main(int argc, const char* argv[])
{
    GraphFixedSize graphFixedSize(8);

    graphFixedSize.setNeighborsOfANode(0, {1, 4});

    graphFixedSize.setNeighborsOfANode(1, {0, 5});

    graphFixedSize.setNeighborsOfANode(2, {3, 5, 6});

    graphFixedSize.setNeighborsOfANode(3, {2, 6, 7});

    graphFixedSize.setNeighborsOfANode(4, {0});

    graphFixedSize.setNeighborsOfANode(5, {1, 2, 6});

    graphFixedSize.setNeighborsOfANode(6, {2, 3, 5, 7});

    graphFixedSize.setNeighborsOfANode(7, {3, 6});

    graphFixedSize.printGraph();

    std::vector<uint32_t> allSrc = {0, 1, 2, 3, 4, 5, 6, 7};
    for (auto s : allSrc)
    {
        graphFixedSize.printDistanceToAllNodesBFS(s);
        graphFixedSize.printPredecessorOfAllNodesBFS(s);
    }

    std::vector<uint32_t> src{0, 2, 4, 6, 7};
    std::vector<uint32_t> dst{0, 1, 3, 5, 2};

    for (uint32_t i = 0; i < src.size(); i++)
    {
        std::cout << "Shortest path between src = " << src[i] << ", and dst = " << dst[i] << ", is " << graphFixedSize.shortestPathBFS(src[i], dst[i]) << std::endl;
    }

    return 0;
}


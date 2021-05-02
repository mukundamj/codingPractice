#include <vector>
#include <iostream>
#include "graphFixedSize.h"
#include "graphVariableSize.h"
#include "gtest/gtest.h"

//using ::testing::EmptyTestEventListener;
//using ::testing::InitGoogleTest;
//using ::testing::Test;
//using ::testing::TestEventListeners;
//using ::testing::TestInfo;
//using ::testing::TestPartResult;
//using ::testing::UnitTest;

namespace {

// About TEST macro:
// Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>

// If we need objects and function that are shared by multiple tests
// then test fixture could be used.
// A test fixture is a place to hold objects and functions shared by
// all tests in a test case.  Using a test fixture avoids duplicating
// the test code necessary to initialize and cleanup those common
// objects for each test.  It is also useful for defining sub-routines
// that your tests need to invoke a lot.
//
// <TechnicalDetails>
//
// The tests share the test fixture in the sense of code sharing, not
// data sharing.  Each test is given its own fresh copy of the
// fixture.  You cannot expect the data modified by one test to be
// passed on to another test, which is a bad idea.
//
// The reason for this design is that tests should be independent and
// repeatable.  In particular, a test should not fail as the result of
// another test's failure.  If one test depends on info produced by
// another test, then the two tests should really be one big test.
//
// The macros for indicating the success/failure of a test
// (EXPECT_TRUE, FAIL, etc) need to know what the current test is
// (when Google Test prints the test result, it tells you which test
// each failure belongs to).  Technically, these macros invoke a
// member function of the Test class.  Therefore, you cannot use them
// in a global function.  That's why you should put test sub-routines
// in a test fixture.
//
// </TechnicalDetails>

// To use a test fixture, derive a class from testing::Test.
class GraphFixedSizeBFS : public testing::Test {
protected:  // You should make the members protected s.t. they can be
            // accessed from sub-classes.
   
     // virtual void SetUp() will be called before each test is run.  You
     // should define it if you need to initialize the variables.
     // Otherwise, this can be skipped.
    void SetUp() override {
        graphFixedSize.setNeighborsOfANode(0, {1, 4});
        graphFixedSize.setNeighborsOfANode(1, {0, 5});
        graphFixedSize.setNeighborsOfANode(2, {3, 5, 6});
        graphFixedSize.setNeighborsOfANode(3, {2, 6, 7});
        graphFixedSize.setNeighborsOfANode(4, {0});
        graphFixedSize.setNeighborsOfANode(5, {1, 2, 6});
        graphFixedSize.setNeighborsOfANode(6, {2, 3, 5, 7});
        graphFixedSize.setNeighborsOfANode(7, {3, 6});
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    //
    // virtual void TearDown() {
    // }
   
    // A helper function that some test uses.
    //static int HelperFunction(...) {
    //    ...    //It could implement and do some checks using ASSERT_EQ, EXPECT_EQ etc.
    //}

    void printGraph()
    {
        graphFixedSize.printGraph();
    }

    // Declares the variables your tests want to use.

    GraphFixedSize graphFixedSize{8};
};

// When you have a test fixture, you define a test using TEST_F
// instead of TEST.

TEST_F(GraphFixedSizeBFS, printGraph)
{
    // This is a dummmy test just used for printing the graph
    printGraph();
}

TEST_F(GraphFixedSizeBFS, DistanceFromSource)
{
    std::vector<uint32_t> expectedDistanceFromSrcNode0 = {0, 1, 3, 4, 1, 2, 3, 4};
    std::vector<uint32_t> expectedDistanceFromSrcNode4 = {1, 2, 4, 5, 0, 3, 4, 5};
    std::vector<uint32_t> expectedDistanceFromSrcNode7 = {4, 3, 2, 1, 5, 2, 1, 0};

    uint32_t sourceNode = 0;
    for (int i = 0; i < graphFixedSize.size(); i++)
    {
        EXPECT_EQ(expectedDistanceFromSrcNode0[i], graphFixedSize.shortestPathBFS(sourceNode, i));
    }

    sourceNode = 4;
    for (int i = 0; i < graphFixedSize.size(); i++)
    {
        EXPECT_EQ(expectedDistanceFromSrcNode4[i], graphFixedSize.shortestPathBFS(sourceNode, i));
    }

    sourceNode = 7;
    for (int i = 0; i < graphFixedSize.size(); i++)
    {
        EXPECT_EQ(expectedDistanceFromSrcNode7[i], graphFixedSize.shortestPathBFS(sourceNode, i));
    }
}

TEST_F(GraphFixedSizeBFS, PredecessorNode)
{
    std::vector<uint32_t> expectedPredecessorWithSrcNode1 = {1, 4294967295, 5, 2, 0, 1, 5, 6};
    std::vector<uint32_t> expectedPredecessorWithSrcNode3 = {1, 5, 3, 4294967295, 0, 2, 3, 3};
    std::vector<uint32_t> expectedPredecessorWithSrcNode5 = {1, 5, 5, 2, 0, 4294967295, 5, 6};

    uint32_t sourceNode = 1;
    for (int i = 0; i < graphFixedSize.size(); i++)
    {
        EXPECT_EQ(expectedPredecessorWithSrcNode1[i], graphFixedSize.predecessorBFS(sourceNode, i));
    }

    sourceNode = 3;
    for (int i = 0; i < graphFixedSize.size(); i++)
    {
        EXPECT_EQ(expectedPredecessorWithSrcNode3[i], graphFixedSize.predecessorBFS(sourceNode, i));
    }

    sourceNode = 5;
    for (int i = 0; i < graphFixedSize.size(); i++)
    {
        EXPECT_EQ(expectedPredecessorWithSrcNode5[i], graphFixedSize.predecessorBFS(sourceNode, i));
    }
}


class GraphVariableSizeBFS : public testing::Test {
protected:

    void SetUp() override {
        graphVariableSize.setNeighborsOfANode(0, {1, 4});
        graphVariableSize.setNeighborsOfANode(1, {0, 5});
        graphVariableSize.setNeighborsOfANode(2, {3, 5, 6});
        graphVariableSize.setNeighborsOfANode(3, {2, 6, 7});
        graphVariableSize.setNeighborsOfANode(4, {0});
        graphVariableSize.setNeighborsOfANode(5, {1, 2, 6});
        graphVariableSize.setNeighborsOfANode(6, {2, 3, 5, 7});
        graphVariableSize.setNeighborsOfANode(7, {3, 6});
    }

    void printGraph()
    {
        graphVariableSize.printGraph();
    }

    GraphVariableSize<uint32_t> graphVariableSize;
};

TEST_F(GraphVariableSizeBFS, printGraph)
{
    // This is a dummmy test just used for printing the graph
    printGraph();
}

TEST_F(GraphVariableSizeBFS, DistanceFromSource)
{
    std::vector<uint32_t> expectedDistanceFromSrcNode0 = {0, 1, 3, 4, 1, 2, 3, 4};
    std::vector<uint32_t> expectedDistanceFromSrcNode4 = {1, 2, 4, 5, 0, 3, 4, 5};
    std::vector<uint32_t> expectedDistanceFromSrcNode7 = {4, 3, 2, 1, 5, 2, 1, 0};

    uint32_t sourceNode = 0;
    for (int i = 0; i < graphVariableSize.size(); i++)
    {
        EXPECT_EQ(expectedDistanceFromSrcNode0[i], graphVariableSize.shortestPathBFS(sourceNode, i));
    }

    sourceNode = 4;
    for (int i = 0; i < graphVariableSize.size(); i++)
    {
        EXPECT_EQ(expectedDistanceFromSrcNode4[i], graphVariableSize.shortestPathBFS(sourceNode, i));
    }

    sourceNode = 7;
    for (int i = 0; i < graphVariableSize.size(); i++)
    {
        EXPECT_EQ(expectedDistanceFromSrcNode7[i], graphVariableSize.shortestPathBFS(sourceNode, i));
    }
}

TEST_F(GraphVariableSizeBFS, PredecessorNode)
{
    // The drawback of using template implementation for GraphVariableSize is that the
    // predecessor list cannot be initialized with std::numeric_limits<T>::max(). This is
    // because this function call max() may not compile for all types of T. When the type of
    // T is uint32_t predecessor list is initialized with 0s hence the predecessor of source
    // node will always be 0.
    std::vector<uint32_t> expectedPredecessorWithSrcNode1 = {1, 0, 5, 2, 0, 1, 5, 6};
    // The predecessor for node 5 is different from that of the GraphFixedSize becasue
    // there are multiple shortest paths possible from source node 3. The GraphVariableSize 
    // uses std::unordered_set for adjacency list, the order of node processing will be different
    // from that in GraphFixedSize which used std::vector for adjacency list.
    std::vector<uint32_t> expectedPredecessorWithSrcNode3 = {1, 5, 3, 0, 0, 6, 3, 3};
    std::vector<uint32_t> expectedPredecessorWithSrcNode5 = {1, 5, 5, 2, 0, 0, 5, 6};

    uint32_t sourceNode = 1;
    for (int i = 0; i < graphVariableSize.size(); i++)
    {
        EXPECT_EQ(expectedPredecessorWithSrcNode1[i], graphVariableSize.predecessorBFS(sourceNode, i));
    }

    sourceNode = 3;
    for (int i = 0; i < graphVariableSize.size(); i++)
    {
        EXPECT_EQ(expectedPredecessorWithSrcNode3[i], graphVariableSize.predecessorBFS(sourceNode, i));
    }

    sourceNode = 5;
    for (int i = 0; i < graphVariableSize.size(); i++)
    {
        EXPECT_EQ(expectedPredecessorWithSrcNode5[i], graphVariableSize.predecessorBFS(sourceNode, i));
    }
}

}   //namespace

class GraphFixedSizeDFS : public testing::Test {
protected:

    void SetUp() override {
        graphFixedSize.setNeighborsOfANode(0, {1, 3});
        graphFixedSize.setNeighborsOfANode(1, {4});
        graphFixedSize.setNeighborsOfANode(2, {4, 5});
        graphFixedSize.setNeighborsOfANode(3, {1});
        graphFixedSize.setNeighborsOfANode(4, {3});
        graphFixedSize.setNeighborsOfANode(5, {5});
    }

    void printGraph()
    {
        graphFixedSize.printGraph();
    }

    GraphFixedSize graphFixedSize{6};
};

TEST_F(GraphFixedSizeDFS, printGraph)
{
    // This is a dummmy test just used for printing the graph
    printGraph();
}

TEST_F(GraphFixedSizeDFS, PredecessorNode)
{
    uint32_t uint32Max = std::numeric_limits<uint32_t>::max();
    std::vector<uint32_t> expectedPredecessor = {uint32Max, 0, uint32Max, 4, 1, 2};

    for (int i = 0; i < graphFixedSize.size(); i++)
    {
        EXPECT_EQ(expectedPredecessor[i], graphFixedSize.predecessorDFS(i));
    }
}

TEST_F(GraphFixedSizeDFS, DiscoveryAndFinishTime)
{
    std::vector<std::pair<uint32_t, uint32_t>> expectedNodeDiscoveryAndFinishTime =
        {
            std::make_pair(1, 8), std::make_pair(2, 7), std::make_pair(9, 12),
            std::make_pair(4, 5), std::make_pair(3, 6), std::make_pair(10, 11)
        };

    for (int i = 0; i < graphFixedSize.size(); i++)
    {
        EXPECT_EQ(expectedNodeDiscoveryAndFinishTime[i], graphFixedSize.nodeDiscoveryAndFinishTimeDFS(i));
    }
}

//If libgtest_main.a is not linked, RUN_ALL_TESTS()
//must be invoked from the below main()
//int main(int argc, char** argv) {
//    std::cout << "Initializing google test" << std::endl;
//    testing::InitGoogleTest(&argc, argv);
//
//    std::cout << "Running all tests" << std::endl;
//    return RUN_ALL_TESTS();
//}

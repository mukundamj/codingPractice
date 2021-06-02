#include <iostream>
#include <vector>
#include <limits>
#include "gtest/gtest.h"

// A peak element is an element that is greater than its neighbors.
// The array may contain multiple peaks, in that case return the index to any
// one of the peaks is fine.
// Input: nums = [1, 2, 3, 1]
// Output: 2 because 2 is the index of 3
// The geeks for geeks has a slightly different definition, it says peak
// number as the which is not lesser than its neighbors. It also has a
// O(lon(n)) algorithm
int findPeakElement(const std::vector<int>&& nums)
{
  for(int i = 0; i < nums.size(); i++)
  {
    int prev = (i - 1 < 0) ? std::numeric_limits<int>::min() : nums[i - 1];
    int next = (i + 1 == nums.size()) ? std::numeric_limits<int>::min() : nums[i + 1];

    if(nums[i] > prev && nums[i] > next)
    {
      return i;
    }
  }

  // If there are no elements, only one element or no peak element in the input vector return 0
  return 0;
}

TEST(FindPeakElementTest, AtleastOnePeakElement)
{
    EXPECT_EQ(1, findPeakElement({1, 2, 1, 3, 5, 6, 4}));
    EXPECT_EQ(5, findPeakElement({1, 1, 1, 3, 5, 6, 4}));
    EXPECT_EQ(6, findPeakElement({1, 2, 3, 4, 5, 6, 7}));
    EXPECT_EQ(0, findPeakElement({7, 6, 5, 4, 3, 2, 1}));
}

TEST(FindPeakElementTest, NoPeakElement)
{
    EXPECT_EQ(0, findPeakElement({1, 1, 1, 1, 1, 1, 1}));
}

TEST(FindPeakElementTest, OnlyOneElement)
{
	EXPECT_EQ(0, findPeakElement({10}));
}

TEST(FindPeakElementTest, NoElements)
{
	EXPECT_EQ(0, findPeakElement({}));
}

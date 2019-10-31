#include "ArrayUtil.h"
#include <iostream>

int
main(int argc, const char* argv[])
{
	std::vector<int> arrayOfNums1 = {1, 1, 1, 1};
	std::vector<int> arrayOfNums2 = {2};
	std::vector<int> arrayOfNums3 = {15, 0};
	std::vector<int> arrayOfNums4 = {0, 9};
	std::vector<int> arrayOfNums5 = {0, 35, 0};
	std::vector<int> arrayOfNums6 = {1, 2, 1};
	std::vector<int> arrayOfNums7 = {1, 2, 3, 2, 1};
	std::vector<int> arrayOfNums8 = {0, 5};

	ArrayUtil arrayUtil;

	//std::cout << "For " << arrayUtil.Print(arrayOfNums1) << "; Expected = 1, Actual = " << arrayUtil.FindPeakElement(arrayOfNums1) << std::endl;
	//std::cout << "For " << arrayUtil.Print(arrayOfNums2) << "; Expected = 2, Actual = " << arrayUtil.FindPeakElement(arrayOfNums2) << std::endl;
	//std::cout << "For " << arrayUtil.Print(arrayOfNums3) << "; Expected = 15, Actual = " << arrayUtil.FindPeakElement(arrayOfNums3) << std::endl;
	//std::cout << "For " << arrayUtil.Print(arrayOfNums4) << "; Expected = 9, Actual = " << arrayUtil.FindPeakElement(arrayOfNums4) << std::endl;
	//std::cout << "For " << arrayUtil.Print(arrayOfNums5) << "; Expected = 35, Actual = " << arrayUtil.FindPeakElement(arrayOfNums5) << std::endl;
	//std::cout << "For " << arrayUtil.Print(arrayOfNums6) << "; Expected = 2, Actual = " << arrayUtil.FindPeakElement(arrayOfNums6) << std::endl;
	//std::cout << "For " << arrayUtil.Print(arrayOfNums7) << "; Expected = 3, Actual = " << arrayUtil.FindPeakElement(arrayOfNums7) << std::endl;
	//std::cout << "For " << arrayUtil.Print(arrayOfNums8) << "; Expected = 5, Actual = " << arrayUtil.FindPeakElement(arrayOfNums8) << std::endl;

	return 0;
}

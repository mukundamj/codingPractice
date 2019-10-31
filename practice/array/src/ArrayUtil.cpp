#include "ArrayUtil.h"
#include <iostream>

int
ArrayUtil::FindPeakElement(const std::vector<int>& inputArray)
{
	size_t arraySize = inputArray.size();
	if (arraySize == 0)
	{
		return 0;
	}

	else
	{
		if (arraySize == 1)
		{
			return inputArray[0];
		}

		else
		{
			for (int i = 1; i < arraySize - 1; i++)
			{
				if ((inputArray[i-1] < inputArray[i]) && (inputArray[i] > inputArray[i + 1]))
				{
					return inputArray[i];
				}
			}
			
			if (inputArray[arraySize - 1] > inputArray[arraySize - 2])
			{
				return inputArray[arraySize -1];
			}

			return 0;
		}
	}
}

void
ArrayUtil::Print(const std::vector<int>& inputArray)
{
	std::cout << "[ ";
	for (auto n = inputArray)
	{
		std::cout << n << " ";
	}
	std::cout << "]" << std::endl;
}

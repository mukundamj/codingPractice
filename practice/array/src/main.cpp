#include <iostream>
#include <vector>
#include <algorithm>

int
main(int argc, const char* argv[])
{
	std::vector<int> numbers;
	std::string readLine;

	std::cout << "Input the numbers" << std::endl;

	while (getline(std::cin, readLine))
	{
		numbers.push_back(stoi(readLine));
	}

	sort(numbers.begin(), numbers.end());

	std::cout << "Sorted numbers are" << std::endl;

	for (auto i : numbers)
	{
		std::cout << i << std::endl;
	}

	return 0;
}

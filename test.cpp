#include <iostream>
#include <cstdlib>
#include "vector.hpp"

int	main(int argc, char **argv)
{
	Vector<int> vec;

	for (int i = 1; i < argc; ++i)
	{
		vec.push_back(atoi(argv[i]));
		std::cout << vec[i - 1] << std::endl;
	}
	vec.swap(1, 2);
	std::cout << "swap" << std::endl;
	std::cout << vec[0] << std::endl;
	std::cout << vec[1] << std::endl;
	std::cout << vec[2] << std::endl;
	std::cout << vec[3] << std::endl;
	std::cout << vec[4] << std::endl;
	return (0);
}
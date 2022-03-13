#include <iostream>
#include <cstdlib>
#include "vector.hpp"

template <typename C>

void	quick_sort(C &cont, int st, int en)
{
	if (st >= en)
		return ;

	int mid = (st + en) / 2;
	cont.swap(st, mid);
	int	pi = cont[st];
	int i = st;
	int j = en;
	while (i < j)
	{
		while (pi < cont[j])
			--j;
		while (i < j && pi >= cont[i])
			++i;
		cont.swap(i, j);
	}
	cont.swap(st, i);
	quick_sort(cont, st, i - 1);
	quick_sort(cont, i + 1, en);
}

int	main(int argc, char **argv)
{
	Vector<int> vec;

	for(int i = 1; i < argc; ++i)
	{
		vec.push_back(atoi(argv[i]));
		std::cout << vec[i - 1] << ' ';
	}
	std::cout << std::endl;
	std::cout << "sorting..." << std::endl;
	quick_sort(vec, 0, argc - 1);
	for(int i = 1; i < argc; ++i)
		std::cout << vec[i - 1] << ' ';
	std::cout << std::endl;
	return (0);
}

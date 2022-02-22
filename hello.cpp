#include <iostream>

int main(void)
{
	int	i;
	int	sum;
	int	max;

	sum = 0;
	i = -1;
	std::cout << "input : ";
	std::cin >> max;
	while (++i < max + 1)
		sum += i;
	std::cout << "sum = " << sum << std::endl;
	return (EXIT_SUCCESS);
}
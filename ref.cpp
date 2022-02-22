#include <iostream>

int	change_value(int &p)
{
	p = 3;
	return (EXIT_SUCCESS);
}

int main(void)
{
	int	num;

	num = 5;
	std::cout << num << std::endl;
	change_value(num);
	std::cout << num << std::endl;
	return (EXIT_SUCCESS);
}
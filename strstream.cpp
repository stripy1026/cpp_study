#include <iostream>
#include <sstream>

int	main(void)
{
	std::istringstream	ss("123");
	int					x;

	ss >> x;
	std::cout << "data : " << x << std::endl;
	return (0);
}
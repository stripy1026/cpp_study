#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{
	std::ofstream	out("test2.txt", std::ios::app);
	std::string		s;

	if (out.is_open())
		out << "Write this.";
	return (0);
}
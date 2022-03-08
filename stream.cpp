#include <iostream>
#include <string>

int	main(void)
{
	std::string s;
	
	std::cin >> s;
	char peek = std::cin.rdbuf()->snextc();
	if (std::cin.fail())
		std::cout << "Failed";
	std::cout << "second word start : " << peek << std::endl;
	std::cin >> s;
	std::cout << "read again : " << s << std::endl;
	return (0);
}
#include <iostream>
#include <string>

int	main(void)
{
	int	t;

	while (true)
	{
//		std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
		std::cin >> std::hex >> t;
		std::cout << "word : " << t << std::endl;
		if (std::cin.fail())
		{
			std::cout << "Type error" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, 'n');
		}
		if (t == 0)
			break ;
	}
	return (0);
}

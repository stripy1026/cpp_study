#include <iostream>

int	main(void)
{
	int	*arr;
	int	size;

	std::cout << "array size : ";
	std::cin >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		std::cout << "arg : ";
		std::cin >> arr[i];
	}
	for (int i = 0; i < size; i++)
		std::cout << i << "th element of arr : " << arr[i] << std::endl;
	delete[] arr;
	return (0);
}

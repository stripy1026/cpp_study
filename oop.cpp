#include <iostream>

class Animal
{
	private:
		int	food;
		int	weight;
	public:
		void	init(int _food, int _weight)
		{
			food = _food;
			weight = _weight;
		}
		void	feed(int amount)
		{
			food += amount;
			weight += (amount / 3);
		}
		void	stat(void)
		{
			std::cout << "food\t: " << food << std::endl;
			std::cout << "weight\t: " << weight << std::endl;
		}
};

int	main(void)
{
	Animal animal;

	animal.init(100, 50);
	animal.feed(30);
	animal.stat();
	return (0);
}
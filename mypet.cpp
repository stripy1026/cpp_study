#include <iostream>

typedef struct s_animal
{
	char	name[30];
	int		age;
	int		health;
	int		food;
	int		clean;
}				t_animal;

void	create_animal(t_animal * animal)
{
	std::cout << "Name : ";
	std::cin >> animal->name;
	std::cout << "Age : ";
	std::cin >> animal->age;
	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void	play(t_animal *animal)
{
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void	one_day_pass(t_animal *animal)
{
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void	show_stat(t_animal *animal)
{
	std::cout << animal->name << "'s status" << std::endl;
	std::cout << "health : " << animal->health << std::endl;
	std::cout << "food : " << animal->food << std::endl;
	std::cout << "clean : " << animal->clean << std::endl;
}

int	main(void)
{
	t_animal	*animal_list[10];
	int			animal_num = 0;
	int			input;
	int			play_with;

	while (1)
	{
		std::cout << "1. Add animal" << std::endl;
		std::cout << "2. play" << std::endl;
		std::cout << "3. show status" << std::endl;
		std::cin >> input;
		switch (input)
		{
			case 1:
				animal_list[animal_num] = new t_animal;
				create_animal(animal_list[animal_num]);
				animal_num++;
				break ;
			case 2:
				std::cout << "which one? : ";
				std::cin >> play_with;
				if (play_with < animal_num)
					play(animal_list[play_with]);
				break ;
			case 3:
				std::cout << "which one? : ";
				std::cin >> play_with;
				if (play_with < animal_num)
					show_stat(animal_list[play_with]);
				break ;
		}
		for (int i = 0; i < animal_num; i++)
			one_day_pass(animal_list[i]);
	}
	for (int i = 0; i < animal_num; i++)
		delete animal_list[i];
	return (0);
}
#ifndef EMPLOYEE_H
# define EMPLOYEE_H

# include <string>
# include <iostream>

class Employee
{
	protected:
		std::string	name;
		int			age;
		std::string	position;
		int			rank;

	public:
		Employee(std::string name, int age, std::string position, int rank)
			: name(name), age(age), position(position), rank(rank) {}
		Employee(const Employee &employee)
		{
			name = employee.name;
			age = employee.age;
			position = employee.position;
			rank = employee.rank;
		}
		Employee() {}
		virtual void	print_info(void);
		virtual int		calculate_pay(void);
};

void	Employee::print_info(void)
{
	std::cout << name << "(" << position << ", " << age << ") ==> "
				<< calculate_pay() << "$" << std::endl;
}

int		Employee::calculate_pay(void) {return (2000 + rank * 500);}

class	Manager : public Employee
{
	private:
	int	year_of_service;

	public:
	Manager(std::string name, int age, std::string position, int rank,
			int year_of_service)
			:	year_of_service(year_of_service),
				Employee(name, age, position, rank) {}
	Manager(const Manager &manager)
		: Employee(manager.name, manager.age, manager.position, manager.rank)
	{
			year_of_service = manager.year_of_service;
	}
	Manager(void) : Employee() {}
	int		calculate_pay(void) override;
	void	print_info(void) override;
};

void	Manager::print_info(void)
{
	std::cout << name << "(" << position << ", " << age
				<< ", YOS = " << year_of_service << ") ==> "
				<< calculate_pay() << "$" << std::endl;
}

int		Manager::calculate_pay(void) 
{
	return (2000 + rank * 500 + 50 * year_of_service);
}

#endif
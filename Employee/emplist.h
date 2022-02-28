#ifndef EMPLIST_H
# define EMPLIST_H

# include "employee.h"

class Emp_list
{
	private:
		int			alloc_employee;
		int			current_employee;
		int			current_manager;
		Employee	**emp_list;
		Manager		**man_list;
	
	public:
		Emp_list(int alloc_employee) : alloc_employee(alloc_employee)
		{
			emp_list = new Employee*[alloc_employee];
			man_list = new Manager*[alloc_employee];
			current_employee = 0;
			current_manager = 0;
		}
		~Emp_list()
		{
			for (int i = 0; i < current_employee; i++)
				delete emp_list[i];
			for (int i = 0; i < current_manager; i++)
				delete man_list[i];
			delete[] emp_list;
			delete[] man_list;
		}
		void	add_employee(Employee *employee);
		void	add_manager(Manager *manager);
		int		current_employee_num(void);
		void	print_employee_info(void);
};

void	Emp_list::add_employee(Employee *employee)
{
	if (current_employee < alloc_employee)
	{
		emp_list[current_employee] = employee;
		current_employee++;
		return ;
	}
	alloc_employee *= 2;
	Employee	**new_list = new Employee*[alloc_employee];
	for (int i = 0; i < current_employee; i++)
		new_list[i] = emp_list[i];
	delete[] emp_list;
	emp_list = new_list;
	emp_list[current_employee] = employee;
	current_employee++;
}

void	Emp_list::add_manager(Manager *manager)
{
	if (current_manager < alloc_employee)
	{
		man_list[current_manager] = manager;
		current_manager++;
		return ;
	}
	alloc_employee *= 2;
	Manager	**new_list = new Manager*[alloc_employee];
	for (int i = 0; i < current_manager; i++)
		new_list[i] = man_list[i];
	delete[] man_list;
	man_list = new_list;
	man_list[current_manager] = manager;
	current_manager++;
}

int		Emp_list::current_employee_num(void)
{
	return (current_employee + current_manager);
}

void	Emp_list::print_employee_info(void)
{
	int	total_pay = 0;
	for (int i = 0; i < current_employee; i++)
	{
		emp_list[i]->print_info();
		total_pay += emp_list[i]->calculate_pay();
	}
	for (int i = 0; i < current_manager; i++)
	{
		man_list[i]->print_info();
		total_pay += man_list[i]->calculate_pay();
	}
	std::cout << "total_pay : " << total_pay << "$" << std::endl;
}

#endif
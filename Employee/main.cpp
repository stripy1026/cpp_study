#include "emplist.h"

int	main(void)
{
	Emp_list emp_list(10);

	emp_list.add_employee(new Employee("H.C Roh", 34, "Plain", 1));
	emp_list.add_employee(new Employee("Ha Ha", 34, "Plain", 1));
	emp_list.add_employee(new Manager("J.S You", 41, "Director", 7, 12));
	emp_list.add_employee(new Manager("J.H Jung", 42, "Manager", 4, 15));
	emp_list.add_employee(new Manager("M.S Park", 43, "Conductor", 5, 13));
	emp_list.add_employee(new Employee("H.D Jung", 36, "Assistant Manager", 2));
	emp_list.add_employee(new Employee("Gill", 36, "Intern", -2));
	emp_list.print_employee_info();
	return (0);
}

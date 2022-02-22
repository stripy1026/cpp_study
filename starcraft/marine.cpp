#include <iostream>
#include <string.h>

class Marine
{
	private:
		static int			total_marine_num;
		const static int	i = 0;
		int					hp_;
		int	 				x_, y_;
		const int			dmg_;
		bool				is_dead_;

	public:
		Marine(void);
		Marine(int x, int y);
		~Marine(void);
		int			attack(void) const;
		Marine		&under_attack(int dmg_earn);
		void		move(int x, int y);
		void		show_stat(void);
		static void	show_total_marine(void);
};

Marine::Marine(void) : hp_(50), x_(0), y_(0), dmg_(5), is_dead_(false)
{
	total_marine_num++;
}

Marine::Marine(int x, int y)
		: hp_(50), x_(x), y_(y), dmg_(5), is_dead_(false)
{
	total_marine_num++;
}
Marine::~Marine(void)
{
	total_marine_num--;
}

void	Marine::show_total_marine(void)
{
	std::cout << " Total marines : " << total_marine_num << std::endl;
}

void	Marine::move(int x, int y)
{
	x_ = x;
	y_ = y;
}

int		Marine::attack(void) const
{
	return (dmg_);
}

Marine	&Marine::under_attack(int dmg_earn)
{
	hp_ -= dmg_earn;
	if (hp_ <= 0)
		is_dead_ = true;
	return (*this);
}

void	Marine::show_stat(void)
{
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Loaction : ( " << x_ << " , " << y_ << " ) "
				<< std::endl;
	std::cout << " HP : " << hp_ << std::endl;
	std::cout << " Current total marines : " << total_marine_num << std::endl;
}

int		Marine::total_marine_num = 0;

int		main(void)
{
	Marine	marine1(2, 3);
	Marine	marine2(3, 5);

	Marine::show_total_marine();
	Marine::show_total_marine();
	marine1.show_stat();
	marine2.show_stat();
	std::cout << std::endl << "Marine1 attacks Marine2 twice" << std::endl;
	marine2.under_attack(marine1.attack()).under_attack(marine1.attack());
	marine1.show_stat();
	marine2.show_stat();
	Marine::show_total_marine();
	return (EXIT_SUCCESS);
}

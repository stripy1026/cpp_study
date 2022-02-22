#include <iostream>

class	Date
{
	private:
		int	year_;
		int	month_;
		int	day_;
	public:
		void	init(int year, int month, int date);
		void	add_day(int inc);
		void	add_month(int inc);
		void	add_year(int inc);
		int		get_current_month_total_days(int year, int month);
		void	show_date(void);
		Date(void)
		{
			year_ = 2022;
			month_ = 2;
			day_ = 17;
		}
		Date(int year, int month, int day)
		{
			year_ = year;
			month_ = month;
			day_ = day;
		}
};

void	Date::init(int year, int month, int day)
{
	year_ = year;
	month_ = month;
	day_ = day;
}

int		Date::get_current_month_total_days(int year, int month)
{
	static int	month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month != 2)
		return (month_day[month - 1]);
	else if (!(year % 4) && (year % 100))
		return (29);
	else
		return (28);
}

void	Date::add_day(int inc)
{
	int	month;

	int current_month_total_days = get_current_month_total_days(year_, month_);

	day_ += inc;
	month = (day_ - 1) / current_month_total_days;
	day_ %= current_month_total_days;
	if (!day_)
		day_ = current_month_total_days;
	add_month(month);

}

void	Date::add_month(int inc)
{
	int	year;

	month_ += inc;
	year = (month_ - 1) / 12;
	month_ %= 12;
	if (!month_)
		month_ = 12;
	add_year(year);
}

void	Date::add_year(int inc)
{
	year_ += inc;
}

void	Date::show_date(void)
{
	std::cout << "Date : " << year_ << ":" << month_ << ":"
				<< day_ << std::endl;
}

int 	main(void)
{
	Date day;

	day.show_date();
	day.add_day(30);
	day.show_date();
	day.add_day(2000);
	day.show_date();
	day.init(2012, 1, 31);
	day.show_date();
	day.add_day(29);
	day.show_date();
	day.add_day(2000);
	day.show_date();
	return (0);
}
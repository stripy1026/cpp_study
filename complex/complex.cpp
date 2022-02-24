#include "complex.h"

class	Complex
{
	private:
		double	real_;
		double	img_;
		double	atod(const char *str, int st, int en) const;

	public:
		Complex(double real, double img) : real_(real), img_(img) {}
		Complex(const Complex &c) { real_ = c.real_, img_ = c.img_; }
		Complex(const char *str);
		Complex &operator=(const Complex &c);
		Complex &operator+=(const Complex &c);
		Complex &operator-=(const Complex &c);
		Complex &operator*=(const Complex &c);
		Complex &operator/=(const Complex &c);
		friend Complex		operator+(const Complex &a, const Complex &b);
		friend Complex		operator-(const Complex &a, const Complex &b);
		friend Complex		operator*(const Complex &a, const Complex &b);
		friend Complex		operator/(const Complex &a, const Complex &b);
		friend std::ostream	&operator<<(std::ostream &os, const Complex &c);
};

Complex::Complex(const char *str)
{
	int 	begin = 0;
	int 	end = strlen(str);
	int		pos_i = -1;
	int		spc = 0;
	int		i = -1;

	img_ = 0.0;
	real_ = 0.0;
	while (++i < end)
	{
		if (str[i] == ' ')
			spc = i;
		else if (str[i] == 'i')
		{
			pos_i = i;
			break ;
		}
	}
	if (pos_i == -1)
	{
		real_ = atod(str, begin, end - 1);
		return ;
	}
	real_ = atod(str, begin, spc);
	img_ = atod(str, spc + 1, end - 1);
}

Complex	operator+(const Complex &a, const Complex &b)
{
	Complex tmp(a.real_ + b.real_, a.img_ + b.img_);

	return (tmp);
}

Complex	operator-(const Complex &a, const Complex &b)
{
	Complex tmp(a.real_ - b.real_, a.img_ - b.img_);
	
	return (tmp);
}

Complex	operator*(const Complex &a, const Complex &b)
{
	Complex tmp(a.real_ * b.real_ - a.img_ * b.img_,
				a.real_ * b.img_ + a.img_ * b.real_);
	
	return (tmp);
}

Complex	operator/(const Complex &a, const Complex &b)
{
	Complex tmp(
	(a.real_ * b.real_ + a.img_ * b.img_) / (b.real_ * b.real_ + b.img_ * b.img_),
	(a.img_ * b.real_ - a.real_ * b.img_) / (b.real_ * b.real_ + b.img_ * b.img_));
	
	return (tmp);
}

Complex &Complex::operator=(const Complex &c)
{
	real_ = c.real_;
	img_ = c.img_;
	return (*this);
}

Complex &Complex::operator+=(const Complex &c)
{
	(*this) = (*this) + c;
	return (*this);
}

Complex &Complex::operator-=(const Complex &c)
{
	(*this) = (*this) - c;
	return (*this);
}

Complex &Complex::operator*=(const Complex &c)
{
	(*this) = (*this) * c;
	return (*this);
}

Complex &Complex::operator/=(const Complex &c)
{
	(*this) = (*this) / c;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Complex &c)
{
	os << "(" << c.real_ << " + " << c.img_ << 'i' << ")";
}

double	Complex::atod(const char *str, int st, int en) const
{
	if (st > en)
		return (0);

	bool	minus = false;
	double	num = 0.0;
	double	dec = 1.0;
	bool	intp = true;

	if (str[st] == '-')
		minus = true;
	if (str[st] == '-' || str[st] == '+')
		st++;
	int i = st - 1;
	while (++i < en + 1)
	{
		if (isdigit(str[i]) && intp)
		{
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			intp = false;
		else if (isdigit(str[i]) && !intp)
		{
			dec /= 10.0;
			num += ((str[i] - '0') * dec);
		}
		else
			break ;
	}
	if (minus)
		num *= -1.0;
	return (num);
}

int		main(void)
{
	Complex	a(0.0, 0.0);
	Complex b(1, 2);

	a = "-1.1 + 3.923i" + a;
	a = a + a;
	std::cout << a << std::endl;
	b = a + b;
	std::cout << b << std::endl;
	return (EXIT_SUCCESS);
}

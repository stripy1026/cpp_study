#include <iostream>

class	Int
{
	private:
		int data_;

	public:
		Int(int data) : data_(data) {}
		Int(const Int &i) : data_(i.data_) {}
		operator int() { return data_; }
};

int	main(void)
{
	Int	x = 3;
	int	a = x + 4;

	x = a * 2 + x + 4;
	std::cout << x << std::endl;
	return (0);
}

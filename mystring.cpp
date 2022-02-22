#include <string.h>
#include <iostream>

class	Mystring
{
	private:
		int		length_;
		char	*str_;

	public:
		Mystring(char c, int n);
		Mystring(const char *s);
		Mystring(const Mystring &s);
		~Mystring(void);
		int		mystrlen(void) const;
		char	*strget(void) const;
		void	mystradd(const Mystring &s);
		void	mystrcpy(const Mystring &s);
};

Mystring::Mystring(char c, int n)
{
	length_ = -1;
	str_ = new char[n + 1];
	while (++length_ < n)
		str_[length_] = c;
	str_[length_] = 0;
}

Mystring::Mystring(const char *s)
{
	length_ = strlen(s);
	str_ = new char[length_ + 1];
	strcpy(str_, s);
}

Mystring::Mystring(const Mystring &s)
{
	length_ = s.length_;
	str_ = new char[length_ + 1];
	this->mystrcpy(s);
}

Mystring::~Mystring(void)
{
	if (str_)
		delete[] str_;
}

int		Mystring::mystrlen(void) const
{
	return (length_);
}

char	*Mystring::strget(void) const
{
	return (str_);
}

void	Mystring::mystradd(const Mystring &s)
{
	char	*tmp;
	int		len;

	if (!length_ || !s.mystrlen())
		return ;
	len = length_ + s.mystrlen();
	tmp = new char[len + 1];
	strcpy(tmp, str_);
	strcpy(tmp + length_, s.strget());
	tmp[len] = 0;
	delete[] str_;
	str_ = tmp;
	length_ = len;
}

void	Mystring::mystrcpy(const Mystring &s)
{
	strcpy(str_, s.strget());
}

int		main(void)
{
	Mystring	*str1 = new Mystring('n', 5);
	Mystring	*str2 = new Mystring("Hello, world!");
	Mystring	*str3 = new Mystring(*str2);

	std::cout << str1->strget() << std::endl;
	std::cout << str2->strget() << std::endl;
	std::cout << str3->strget() << std::endl;
	std::cout << str3->mystrlen() << std::endl;
	str2->mystradd(*str1);
	std::cout << str1->strget() << std::endl;
	std::cout << str2->strget() << std::endl;
	std::cout << str3->strget() << std::endl;
	str2->mystrcpy(*str1);
	std::cout << str1->strget() << std::endl;
	std::cout << str2->strget() << std::endl;
	std::cout << str3->strget() << std::endl;
	delete str1;
	delete str2;
	delete str3;
	return (EXIT_SUCCESS);
}

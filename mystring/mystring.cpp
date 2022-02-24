#include "mystring.h"

class	Mystring
{
	private:
		char	*str_;
		int		length_;
		int		mem_cap_;

	public:
		explicit Mystring(int cap);
		Mystring(const char c, int n);
		Mystring(const char *s);
		Mystring(const Mystring &s);
		~Mystring(void);
		int			mystrlen(void) const;
		int			memcap(void) const;
		void		reserve(int size);
		void		print(void) const;
		Mystring	&assign(const Mystring &str);
		Mystring	&assign(const char *str);
		char		at(int i) const;
		Mystring	&insert(int loc, const Mystring &str);
		Mystring	&insert(int loc, const char *str);
		Mystring	&insert(int loc, const char c, int n);
		Mystring	&erase(int loc, int num);
		int			find(int find_from, const Mystring &str) const;
		int			find(int find_from, const char *str) const;
		int			find(int find_from, const char c) const;
		int			compare(const Mystring &str) const;
		bool		operator==(Mystring &str);
		char		&operator[](const int index);
};

Mystring::Mystring(int cap)
{
	str_ = new char[cap];
	length_ = 0;
	mem_cap_ = cap;
	std::cout << "Cap : " << mem_cap_ << std::endl;
}

Mystring::Mystring(const char c, int n)
{
	length_ = -1;
	str_ = new char[n];
	while (++length_ < n)
		str_[length_] = c;
	mem_cap_ = length_;
}

Mystring::Mystring(const char *s)
{
	length_ = strlen(s);
	mem_cap_ = length_;
	str_ = new char[length_];
	strncpy(str_, s, length_);
}

Mystring::Mystring(const Mystring &s)
{
	length_ = s.length_;
	mem_cap_ = s.length_;
	str_ = new char[length_ ];
	strncpy(str_, s.str_, length_);
}

Mystring::~Mystring(void)
{
	delete[] str_;
}

int			Mystring::mystrlen(void) const
{
	return (length_);
}

int			Mystring::memcap(void) const
{
	return (mem_cap_);
}

void		Mystring::reserve(int size)
{
	if (size > mem_cap_)
	{
		char* tmp = str_;
		
		str_ = new char[size];
		mem_cap_ = size;
		strncpy(str_, tmp, length_);
		delete[] tmp;
	}
}

void		Mystring::print(void) const
{
	int	i;

	i = -1;
	while (++i < length_)
		std::cout << str_[i];
	std::cout << std::endl;
}

Mystring	&Mystring::assign(const Mystring &str)
{
	if (str.length_ > mem_cap_)
	{
		delete[] str_;
		str_ = new char[str.length_];
		mem_cap_ = str.length_;
	}
	strncpy(str_, str.str_, str.length_);
	length_ = str.length_;
	return (*this);
}

Mystring	&Mystring::assign(const char *str)
{
	int	len;

	len = strlen(str);
	if (len > mem_cap_)
	{
		delete[] str_;
		str_ = new char[len];
		mem_cap_ = len;
	}
	strncpy(str_, str, len);
	length_ = len;
	return (*this);
}

char		Mystring::at(int i) const
{
	if (i > length_ - 1 || i < 0)
		return (0);
	return (str_[i]);
}

Mystring	&Mystring::insert(int loc, const Mystring &str)
{
	if (loc < 0 || loc > length_)
		return (*this);
	if (length_ + str.length_ > mem_cap_)
	{
		char *tmp = str_;

		if (mem_cap_ * 2 > length_ + str.length_)
			mem_cap_ *= 2;
		else
			mem_cap_ = length_ + str.length_;
		str_ = new char[mem_cap_];
		strncpy(str_, tmp, loc);
		strncpy(str_ + loc, str.str_, str.length_);
		strncpy(str_ + loc + str.length_, tmp + loc, length_ - loc);
		delete[] tmp;
		length_ += str.length_;
		return (*this);
	}
	for (int i = length_ - 1; i >= loc, i--;)
		str_[i + str.length_] = str_[i];
	strncpy(str_ + loc, str.str_, str.length_);
	length_ += str.length_;
	return (*this);
}

Mystring	&Mystring::insert(int loc, const char *str)
{
	Mystring	tmp(str);

	return (insert(loc, tmp));
}

Mystring	&Mystring::insert(int loc, const char c, int n)
{
	Mystring	tmp(c, n);

	return (insert(loc, tmp));
}

Mystring	&Mystring::erase(int loc, int num)
{
	if (num < 1 || loc < 0 || loc > length_)
		return (*this);
	if (loc + num > length_)
	{
		length_ = loc;
		return (*this);
	}
	for (int i = loc + num; i < length_; i++)
		str_[i - num] = str_[i];
	length_ -= num;
	return (*this);
}

int			Mystring::find(int find_from, const Mystring &str) const
{
	if (!str.length_)
		return (-1);
	for (int i = find_from; i < length_ - str.length_ + 1; i++)
	{
		int j;

		for (j = 0; j < str.length_; j++)
			if (str_[i + j] != str.str_[j])
				break ;
		if (j == str.length_)
			return (i);
	}
	return (-1);
}

int			Mystring::find(int find_from, const char *str) const
{
	Mystring	tmp(str);
	
	return (find(find_from, tmp));
}

int			Mystring::find(int find_from, const char c) const
{
	Mystring	tmp(c, 1);
	
	return (find(find_from, tmp));
}

int			Mystring::compare(const Mystring &str) const
{
	int	len;
	int	i;

	len = length_ > str.length_ ? str.length_ : length_;
	i = -1;
	while (++i < len)
	{
		if (str_[i] != str.str_[i])
			return (str_[i] - str.str_[i]);
	}
	if (length_ > str.length_)
		return (str_[i]);
	else if (length_ < str.length_)
		return (str.str_[i]);
	return (0);
}

bool	Mystring::operator==(Mystring &str)
{
	return (!compare(str));
}

char	&Mystring::operator[](const int index)
{
	return (str_[index]);
}

int		main(void)
{
	Mystring str1("a word");
	Mystring str2("sentence");
	Mystring str3("sentence");

	if (str1 == str2)
		std::cout << "str1 == str2." << std::endl;
	else
		std::cout << "str1 != str2." << std::endl;
	if (str2 == str3)
		std::cout << "str2 == str3." << std::endl;
	else
		std::cout << "str2 != str3." << std::endl;
	str1[0] = 'b';
	str1.print();
	return (EXIT_SUCCESS);
}

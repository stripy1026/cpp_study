#ifndef VECTOR_H
# define VECTOR_H

template	<typename T>
class Vector
{
	private:
		T	*data;
		int	capacity;
		int	length;
	public:
		Vector(int n = 1) : data(new T[n]), capacity(n), length(n) {}
		void	push_back(T s)
		{
			if (capacity < length + 1)
			{
				T	*tmp = new T[capacity * 2];
				for (int i = 0; i < length; ++i)
					tmp[i] = data[i];
				delete[] data;
				data = tmp;
				capacity *= 2;
			}
			data[length++] = s;
		}
		T		operator[](int i) { return (data[i]); }
		void	remove(int x)
		{
			for (int i = x + 1; i < length; ++i)
				data[i - 1] = data[i];
			length--;
		}
		int		size(void) { return (length); }
		void	swap(int i, int j)
		{
			T	tmp = data[i];
			
			data[i] = data[j];
			data[j] = tmp;
		}
		~Vector(void)
		{
			if (data)
				delete[] data;
		}
};

#endif

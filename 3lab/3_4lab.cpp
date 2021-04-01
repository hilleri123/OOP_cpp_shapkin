
#include <vector>
#include <iostream>

template<class T>
class Stack
{
public:
	Stack() {}

	Stack(const Stack& ) = default;
	Stack(Stack&& ) = default;

	bool empty()
	{
		return _vec.size() == 0;
	}

	void push(const T& item)
	{
		_vec.push_back(item);
	}

	void push(T&& item)
	{
		_vec.push_back(item);
	}

	T& top()
	{
		return _vec.beck();
	}

	void pop()
	{
		_vec.pop_back();
	}


	friend std::ostream& operator<<(std::ostream& s, Stack<T> b)
	{
		for (auto i = b._vec.begin(); i < b._vec.end(); ++i)
			s << *i << " ";
		return s;
	}

	friend Stack operator+(Stack<T> a, Stack<T> b)
	{
		Stack result(a);
		for (auto i = b._vec.begin(); i < b._vec.end(); ++i)
			result.push(*i);
		return result;
	}
protected:
	std::vector<T> _vec;
};


int main()
{
	Stack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	std::cout << a << std::endl;
	a.pop();
	a.pop();
	std::cout << a << std::endl;
	std::cout << (a + a) << std::endl;
}



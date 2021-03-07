
#include <iostream>
#include <cstring>

#define PRINT(type, symbol) \
	void print() \
	{ \
		type a, b; \
		std::cin >> a >> b; \
		std::cout << a << " " #symbol " " << b << " = " << plus(a, b) << std::endl; \
	}

namespace boolean {
	inline bool plus(bool a, bool b)
	{
		return (!a || !b) && (a || b);
	}

	PRINT(bool, (+))
};

namespace common {
	inline int plus(int a, int b)
	{
		return a + b;
	}

	PRINT(int, +)
}

#undef PRINT



int main(int argc, char** argv)
{
	//c - common, b - mod 2
	const std::string c("c"), b("b");
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			std::string tmp(argv[i]);
			if (tmp == c)
				common::print();
			else if(tmp == b)
				boolean::print();
		}
	} else
		common::print();


}



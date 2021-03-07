

#include <iostream>

#define FOO(name, type, operation) \
	inline void name(type a) \
	{ \
		std::cout << #name << "(" #type " a)" << std::endl; \
		operation; \
	}

FOO(foo0, int, a++)
FOO(foo1, int&, a++)
FOO(foo2, int*, (*a)++)


#undef FOO

int main()
{
	int a;
	std::cin >> a;

#define PRINT(step) \
	std::cout << "step" #step " a = " << a << std::endl << std::endl;

	PRINT(0)

	foo0(a);
	PRINT(1)
	
	foo1(a);
	PRINT(2)
	
	foo2(&a);
	PRINT(3)
	
#undef PRINT

}


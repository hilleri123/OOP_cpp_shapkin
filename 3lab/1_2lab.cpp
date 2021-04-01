

#include <cstring>
#include <iostream>


template<class T>
T min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}


#define MIN(a, b) \
	(a < b ? a : b)


int main()
{
	
	std::cout << min(1, 2) << " " << min(2, 1) << std::endl;
	std::cout << MIN(1, 2) << " " << MIN(2, 1) << std::endl;

	return 0;
};



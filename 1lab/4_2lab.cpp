#include <stdlib.h>
#include <iostream>

using namespace std;

void fv() {
	int i = int(123);
	cout << "i = " << i << endl;
}

void fp1()
{
	int* i = new int(123);
	cout << "*i = " << *i << endl;
	delete i;
}

void fp2() 
{
	int* i = new int(123);
	cout << "*i = " << *i << endl;
	delete i;
	i = new int(456);
	cout << "*i = " << *i << endl;
	delete i;
}

int* fr() 
{
	int i = int(123);
	int* ip = &i;
	cout << "i = " << i << endl;
	return ip;
}

int main()
{
	fv();
	fp1();
	fp2();
	int *ifr = fr();
	cout << "*ifr = " << *ifr << endl;
	return 0;
}


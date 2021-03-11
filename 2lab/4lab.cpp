

#define VALUE

#define REFERENCE

#define POINTER


class A
{
public:
	A() : _a(new int(0))
	{}

	A(const A& a) : _a(new int(*(a._a)))
	{}

	A(A&& a) : _a(new int(*(a._a)))
	{}

	~A()
	{
		delete _a;
	}
protected:
	int* _a;
};



#ifdef VALUE
void foo0(A a)
{}
#endif

#ifdef REFERENCE
void foo(A& a)
{}
#endif

#ifdef POINTER
void foo(A* a)
{}
#endif


int main()
{
	A a;
#ifdef VALUE
	foo0(a);
#endif

#ifdef REFERENCE
	foo(a);
#endif

#ifdef POINTER
	foo(&a);
#endif


	return 0;
}



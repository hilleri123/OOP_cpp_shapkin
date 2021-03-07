
#include <iostream>


class A
{
protected:
	enum func_type {constructor, destructor, other};
public:
	explicit A(int id = 0) : _id(id)
	{
		print(constructor, "A");
	}


	void print(func_type t, std::string name) const
	{
		std::string tmp;
		switch (t) {
			case constructor:
				tmp = "created";
				break;
			case destructor:
				tmp = "deleted";
				break;
			case other:
				tmp = "something done";
		}
		std::cout << tmp << " " << name << "(" << _id << ")" << std::endl;
	}

	virtual ~A()
	{
		print(destructor, "A");
	}
protected:
	int _id;
};


#define NEW_CLASS(cls, parent) \
	class cls : public parent \
	{ \
	public: \
		explicit cls(int id = 0) : parent(id) \
		{ \
			print(constructor, #cls); \
		} \
		virtual ~cls() override \
		{ \
			print(destructor, #cls); \
		} \
	};

NEW_CLASS(B, A)
NEW_CLASS(C, B)
NEW_CLASS(D, C)

NEW_CLASS(E, A)
NEW_CLASS(F, E)



#undef NEW_CLASS


int main()
{
	A(1);
	std::cout << std::endl;

	B(2);
	std::cout << std::endl;

	C(3);
	std::cout << std::endl;

	D(4);
	std::cout << std::endl;

	E(5);
	std::cout << std::endl;

	F(6);
	std::cout << std::endl;
}




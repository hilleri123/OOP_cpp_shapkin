
#include <iostream>
#include <string>
#include <algorithm>



class Expr
{
public:
	virtual int eval() = 0;
	virtual ~Expr() {}
};

class Num : public Expr
{
public:
	explicit Num(int n = 0) : _n(n)
	{}

	virtual int eval() override
	{
		return _n;
	}
protected:
	int _n;
};

class BOperation : public Expr
{
public:
	explicit BOperation(Expr* left, Expr* right) : _left(left), _right(right)
	{}

	virtual ~BOperation()
	{
		delete _left;
		delete _right;
	}
protected:
	Expr* _left;
	Expr* _right;
};

class Add : public BOperation
{
public:
	explicit Add(Expr* left, Expr* right) : BOperation(left, right)
	{}

	virtual int eval() override
	{
		return _left->eval() + _right->eval();
	}
};



class Substract : public BOperation
{
public:
	explicit Substract(Expr* left, Expr* right) : BOperation(left, right)
	{}

	virtual int eval() override
	{
		return _left->eval() - _right->eval();
	}
};


Expr* create_expr(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

	const std::string::size_type not_found = std::string::npos;
	if (str.find('+') != not_found && str.find('+') != str.size()-1) {
		return new Add(
				create_expr(str.substr(0, str.find('+'))),
				create_expr(str.substr(str.find('+')+1))
				);
	} else if (str.find('-') != not_found && str.find('-') != str.size()-1) {
		return new Substract(
				create_expr(str.substr(0, str.find('-'))),
				create_expr(str.substr(str.find('-')+1))
				);
	} else 
		return new Num(std::stoi(str));
}


int main()
{
	std::string tmp;
	//std::cin >> tmp;
	std::getline(std::cin, tmp);
	Expr* expr = create_expr(tmp);
	std::cout << tmp << " = " << expr->eval() << std::endl;
	delete expr;
};


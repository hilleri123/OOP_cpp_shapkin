
#include <iostream>


class Collection
{
public:
	explicit Collection(std::size_t i = 1) : _buf(new int[i]), _size(i)
	{}

	virtual void put(int ) = 0;
	virtual int take() = 0;

	virtual ~Collection()
	{
		delete[] _buf;
	}

	int get(std::size_t i) const
	{
		if (i >= _size)
			return _buf[_size-1];
		return _buf[i];
	}

protected:
	int* _buf;
	std::size_t _size;
};


class Stack : public Collection
{
public:
	explicit Stack(std::size_t i) : Collection(i), _pos(0)
	{}

	virtual void put(int el) override
	{
		if (_pos >= _size)
			return ;
		_buf[_pos++] = el;
	}

	virtual int take() override
	{
		if (_pos > 0)
			return _buf[_pos--];
		return _buf[0];
	}
protected:
	std::size_t _pos;
};


class Queue : public Collection
{
public:
	explicit Queue(std::size_t i) : Collection(i), _pos(0), _queue_size(0)
	{}

	virtual void put(int el) override
	{
		if (_queue_size+1 >= _size)
			return ;
		_buf[(_pos+_queue_size++)%_size] = el;
	}

	virtual int take() override
	{
		if (_queue_size-- > 0)
			return _buf[_pos++];
		return _buf[0];
	}
protected:
	std::size_t _pos;
	std::size_t _queue_size;
};



int main(int argc, char** argv)
{
	const std::size_t N = 2;
	const std::size_t M = 6;
	Collection** array = new Collection*[N];
	for (int i = 0; i < N; ++i) {
		if (i < N/2) 
			array[i] = new Stack(M);
		else 
			array[i] = new Queue(M);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2*M; ++j) {
			if (j < 2*M/3 || j > 4*M/3 || j % 3 == 1)
				array[i]->put(j);
			else
				array[i]->take();
		}
	}


	for (int i = 0; i < N; ++i) {
		std::cout << "Collection " << i << std::endl;
		for (int j = 0; j < M; ++j)
			std::cout << array[i]->get(j) << " ";
		std::cout << std::endl;
		delete array[i];
	}
	delete[] array;
		
}



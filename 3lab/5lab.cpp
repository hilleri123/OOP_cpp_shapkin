
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <stdexcept>
#include <set>

class Graph
{
	using vec = std::vector<int>;
public:
	Graph(const vec& a, const vec& b)
	{
		if (a.size() != b.size())
			throw std::invalid_argument("a.size() != b.size()"); //мне очень стыдно, что я бросаю в конструкторе

		std::map<int, std::set<int>> tmp;
		for (auto i = a.begin(), j = b.begin(); i < a.end() && j < b.end(); ++i, ++j) {
			auto val = _m.find(*i);
			if (val != _m.end())
				val->second.push_back(*j);
			else
				_m[*i] = vec({*j});

			val = _m.find(*j);
			if (val == _m.end())
				_m[*j] = vec();
		}

		for (auto i = _m.begin(); i != _m.end(); ++i) {
			std::set<int> tmp_set(i->second.begin(), i->second.end());
			std::set<int> res;
			//std::cout << "out " << i->first << std::endl;
			outgoing(res, tmp_set);
			tmp[i->first] = res;
		}
		
		_m.clear();
		for (auto i = tmp.begin(); i != tmp.end(); ++i) {
			_m[i->first] = vec(i->second.begin(), i->second.end());
			_nodes.insert(i->first);
		}
	}

	int numOutgoing(const int node_id) const
	{
		return adjacent(node_id).size();
	}

	const vec& adjacent(const int node_id) const
	{
		if (_m.find(node_id) == _m.end())
			throw std::invalid_argument("node doesnt exist");

		return _m.at(node_id);
	}

	const std::set<int>& nodes() const
	{
		return _nodes;
	}
protected:

	void outgoing(std::set<int>& checked, std::set<int> next) 
	{
		for (auto i = next.begin(); i != next.end(); ++i) {
			if (checked.find(*i) == checked.end()) {
				checked.insert(*i);
				std::set<int> tmp_next(_m.at(*i).begin(), _m.at(*i).end());
				//std::cout << "in " << checked.size() << " out " << *i << std::endl;
				outgoing(checked, tmp_next);
			}
		}
	}

	std::set<int> _nodes;
	std::map<int, vec> _m;
};


int main()
{
	std::vector<int> a = {1, 2, 3, 4, 1}, b = {2, 3, 4, 1, 5};

	Graph g(a, b);
	for (auto i = g.nodes().begin(); i != g.nodes().end(); ++i) {
		std::cout << *i << " : ";
		const std::vector<int>& tmp = g.adjacent(*i);
		for (auto j = tmp.begin(); j < tmp.end(); ++j)
			std::cout << *j << " ";
		std::cout << std::endl;
	}

	return 0;
};



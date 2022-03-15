#include "List.h"
#include <string>

int main()
{
	List a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(56);
	List b(a);
	a[1] = 324;
	b.reverse();
	b.push_back(2);
	b.front() = 15;
	b.back() = 32;
	b.swap(a);
	b[2] = 18;
	a[0] = 92;
	for (size_t i = 0; i < b.size(); ++i)
		std::cout << b[i] << '\n';
	std::cout << "-----------------" << '\n';
	for (size_t i = 0; i < a.size(); ++i)
		std::cout << a[i] << '\n';
	auto it = List::reverse_Iterator(a.rbegin());
	std::cout << "-----------------" << '\n';
	while (it != a.rend())
	{
		std::cout << *it << '\n';
		it++;
	}
}
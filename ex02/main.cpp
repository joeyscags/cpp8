#include <iostream>
#include <list>
#include "MutantStack.hpp"

static void testMutantStack()
{
	std::cout << "--- MutantStack ---\n";
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << "\n";
	mstack.pop();
	std::cout << mstack.size() << "\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it  = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
	std::stack<int> s(mstack);
}

static void testList()
{
	std::cout << "--- std::list ---\n";
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << "\n";
	lst.pop_back();
	std::cout << lst.size() << "\n";
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it  = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\n";
		++it;
	}
}

int main(void)
{
	testMutantStack();
	testList();
	return 0;
}

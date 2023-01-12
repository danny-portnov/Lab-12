#define   _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
bool is_palindrom(unsigned num);
list<int>::iterator myfind(list<int>& l, int elem);



bool is_palindrom(unsigned num) {
	vector<unsigned> number;
	vector<unsigned> reversed_number;
	while (num) {
		number.push_back(num % 10);
		reversed_number.push_back(num % 10);
		num /= 10;
	}
	int size = number.size();
	reverse(reversed_number.begin(), reversed_number.end());    
	if (number == reversed_number)
		return true;
	return false;

}

list<int>::iterator myfind(list<int>& l, int elem) {
	list<int>::iterator it;
	cout << "list contains:";
	for (it = l.begin(); it != l.end(); ++it)
		cout << " " << *it;
	cout << endl;
	return find(l.begin(), l.end(), elem);

	
}

void test_myfind() {

	list<int> L;
	list<int>::iterator i;
	L.push_back(0);
	L.push_front(10);
	L.insert(++L.begin(), 2);
	i = myfind(L, 2);
}

int main()
{


	is_palindrom(13241);
	test_myfind();

	return 0;
}

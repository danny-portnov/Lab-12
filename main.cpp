#define   _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <stack>
#include <string>
#include <queue>
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
string infix2postfix(const string& infix);
void sort_array(int* arr, int len);



string infix2postfix(const string& infix) {
	stack<char> stack;
	string postfix;
	string::const_iterator infix_iterator = infix.begin();
	for (; infix_iterator != infix.end(); infix_iterator++) {
		if (isdigit(*infix_iterator)) {
			postfix.push_back(*infix_iterator);
		}
		else {
			switch (*infix_iterator)
			{
			case ')': {
				postfix.push_back(stack.top());
				stack.pop();
				break;
			}
			case '(':
				continue;
			default: //is operator
				stack.push(*infix_iterator);
			}
		}
	}
	return postfix;
}

void sort_array(int* arr, int len) {
	priority_queue<int> pq(arr, arr + len);
	for (int i = 0; i < len; i++)
	{
		arr[i] = pq.top();
		pq.pop();
	}
}

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

	cout << infix2postfix("(2+((3+4)*(5*6)))") << endl; //234+56**+
	cout << infix2postfix("(2+((3*4)+5))") << endl; //234*+5+ or 234*5++ also okay
	cout << infix2postfix("((1+2)-((3*(4/5))+6))") << endl; //12+345/*6+-
	int arr[] = { 3,7,4,9,1 };
	sort_array(arr, 5); // 9 7 4 3 1
	return 0;
}

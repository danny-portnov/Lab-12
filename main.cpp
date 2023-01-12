
#define   _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG



int main()
{

	return 0;
}

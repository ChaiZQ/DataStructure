#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	string str;
	stack<string> sstack;
	while (cin >> str)
		sstack.push(str);
	while (sstack.size() > 1) {
		cout << sstack.top() << ' ';
		sstack.pop();
	}
	cout << sstack.top();

	system("pause");
	return 0;
}
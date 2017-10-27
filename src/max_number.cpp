#include <iostream>
#include <string>
#include <vector>

using namespace std;

//问题代码，只遍历了一遍，只比较了原来相邻的数，删除后可能还会有新的出现，于是漏掉了！

int main(int argc, char**argv) {
	string str;
	int num;
	cin >> str >> num;
	int count = 0;
	for (string::iterator it = str.begin(); (it + 1) != str.end();) {
		if (*it < *(it + 1)) {
			it = str.erase(it);
			if (count++ >= num)break;
		}
		else {
			it++;
		}
	}
	while (count++ < num) {
		str.erase(str.end() - 1);
	}
	cout << str;

	return 0;
}
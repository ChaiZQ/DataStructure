#include <iostream>
#include <string>
#include <vector>

using namespace std;

//������룬ֻ������һ�飬ֻ�Ƚ���ԭ�����ڵ�����ɾ������ܻ������µĳ��֣�����©���ˣ�

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
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str;
	while (getline(cin, str)) {
		int i = 0, j = str.size() - 1;
		while (i < j) {
			char tmp = str[i];
			str[i++] = str[j];
			str[j--] = tmp;
		}
		int last_pos = 0;
		for (int k = 0; k < str.size(); ++k) {
			if (str[k] == ' ') {
				for (int cnt = k - 1; cnt >= last_pos; --cnt) {
					std::cout << str[cnt];
				}
				std::cout << " ";
				last_pos = k + 1;
			}
			else if (k == str.size() - 1) {
				for (int cnt = k; cnt >= last_pos; --cnt) {
					std::cout << str[cnt];
				}
			}
		}
		str.clear();
	}

	system("pause");
	return 0;
}
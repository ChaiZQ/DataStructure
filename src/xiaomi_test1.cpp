#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(int argc, char**argv) {

	int total_num = 0;
	cin >> total_num;
	while (total_num--) {
		string str;
		cin >> str;
		int w = 0, u = 0, x = 0, g = 0, r = 0, f = 0, s = 0, o = 0, z = 0, i = 0;
		vector<int>num;
		for (int k = 0; k < str.length(); ++k) {
			if (str[k] == 'W')
				w++;
			if (str[k] == 'U')
				u++;
			if (str[k] == 'X')
				x++;
			if (str[k] == 'G')
				g++;
			if (str[k] == 'R')
				r++;
			if (str[k] == 'F')
				f++;
			if (str[k] == 'S')
				s++;
			if (str[k] == 'O')
				o++;
			if (str[k] == 'Z')
				z++;
			if (str[k] == 'I')
				i++;
		}
		int num_0 = g, num_1 = i - g - x - f + u, num_2 = z, num_3 = o - w - u - z, num_4 = w, num_5 = r - z - u, num_6 = u, num_7 = f - u, num_8 = x, num_9 = s - x;

		for (int j = 0; j < num_0; ++j)
			cout << 0;
		for (int j = 0; j < num_1; ++j)
			cout << 1;
		for (int j = 0; j < num_2; ++j)
			cout << 2;
		for (int j = 0; j < num_3; ++j)
			cout << 3;
		for (int j = 0; j < num_4; ++j)
			cout << 4;
		for (int j = 0; j < num_5; ++j)
			cout << 5;
		for (int j = 0; j < num_6; ++j)
			cout << 6;
		for (int j = 0; j < num_7; ++j)
			cout << 7;
		for (int j = 0; j < num_8; ++j)
			cout << 8;
		for (int j = 0; j < num_9; ++j)
			cout << 9;
	}
	cout << endl;

	system("pause");
	return 0;
}
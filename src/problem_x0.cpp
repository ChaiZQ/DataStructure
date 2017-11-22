#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char**argv) {
	int N;
	cin >> N;
	int* price = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> price[i];
	sort(price, price + N);
	int cnt = 1, i = 1;
	for (; i < N; ++i) {
		if (price[i] == price[i - 1])
			continue;
		else
			cnt++;
		if (cnt == 3)
			break;
	}
	if (cnt == 3)
		cout << price[i];
	else
		cout << -1;
	system("pause");
	return 0;
}
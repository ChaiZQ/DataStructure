#include <queue>
#include <iostream>
using namespace std;
int main(int argc, char**argv) {
	int n;
	while (cin >> n) {
		int*arr = new int[n];
		queue<int> Q;
		for (int i = 0; i < n; ++i) {
			Q.push(i);
		}
		int cnt = 1;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			Q.push(x);
			x = Q.front();
			arr[x] = cnt++;
			Q.pop();
		}
		for (int i = 0; i < n - 1; ++i)
			cout << arr[i] << " ";
		cout << arr[n - 1] << endl;
		delete arr;
	}
	system("pause");
	return 0;
}
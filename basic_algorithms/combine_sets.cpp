#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char**argv) {
	int n, m;
	cin >> n >> m;
	vector<int> A(n, 0);
	vector<int> B(m, 0);
	vector<int> AB(n + m, 0);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> B[i];
	}
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	int a = 0, b = 0, c = 0;
	while (a < n && b < m) {
		if (A[a] < B[b]) {
			AB[c++] = A[a++];
		}
		else if (A[a] > B[b]) {
			AB[c++] = B[b++];
		}
		else if (A[a] == B[b]) {
			AB[c++] = A[a++];
			b++;
		}
	}
	while (a < n) {
		AB[c++] = A[a++];
	}
	while (b < m) {
		AB[c++] = B[b++];
	}
	for (int i = 0; i < c - 1; ++i)
		cout << AB[i] << " ";
	cout << AB[c - 1];

	system("pause");
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int solve(int r, int g, int b)
{
	if (r == g == b)
		return r;
	int a, b, c;
	if (r > g)
	{
		a = r;
		c = g;
	}
}
int main(int argc, char**argv) {
	int n;
	while (cin >> n) {
		int r, g, b;
		cin >> r >> g >> b;
		cout << solve(r, g, b) << endl;
	}
	return 0;
}
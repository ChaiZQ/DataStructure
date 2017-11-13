//小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
//这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K + X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
//例如：
//N = 4，M = 24：
//4->6->8->12->18->24
//于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int leastStep(vector<int>&flag, int start, int end) {
	if (flag[start] != -2)
		return flag[start];
	int steps;
	if (start == end)
		steps = 0;
	else if (start > end)
		steps = -1;
	else {
		steps = 0x7fffffff;
		for (int s = start / 2; s >= 2; s--) {
			if (start%s != 0)
				continue;
			int tmp = leastStep(flag, start + s, end);
			if (tmp == -1)
				continue;
			steps = min(steps, tmp);
		}
		if (steps != 0x7fffffff) {
			steps = 1 + steps;
		}
		else
			steps = -1;
	}
	if (start <= end)
		flag[start] = steps;
	return steps;

}
int main(int argc, char**argv) {
	int N, M;
	cin >> N >> M;
	vector<int>flag(M + 1, -2);
	cout << leastStep(flag, N, M);
	return 0;
}
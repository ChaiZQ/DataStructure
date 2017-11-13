//С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
//����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K + X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
//���磺
//N = 4��M = 24��
//4->6->8->12->18->24
//����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��

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
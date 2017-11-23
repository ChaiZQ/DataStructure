//��Ŀ����
//�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
//�������� :
//ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n(1 <= n <= 50)����ʾѧ���ĸ�������������һ�У����� n ����������˳���ʾÿ��ѧ��������ֵ ai�� - 50 <= ai <= 50������������һ�а�������������k �� d(1 <= k <= 10, 1 <= d <= 50)��
//������� :
//���һ�б�ʾ���ĳ˻���
//ʾ��1
//����
//
//3
//7 4 7
//2 50
//���
//
//49

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define inf LLONG_MAX
#define _inf LLONG_MIN
//���index��ʼ����������������е���Сֵ�����ֵ��������С�������flag����0�����1����С
//max_list: max_list[i][j]��ʾ��i��β��ѡ��j���˵����ֵ
//min_list: min_list[i][j]...

//���µݹ��㷨��ʱ
long long max_power(int cur_index, vector<vector<long long>>& max_list, vector<vector<long long>>& min_list, int*power, int len, int k, int d, int flag) {
	if (cur_index >= k && cur_index<=len && k > 0) {
		if (flag == 0 && max_list[cur_index][k] != inf)
			return max_list[cur_index][k];
		else if (flag == 1 && min_list[cur_index][k] != inf)
			return min_list[cur_index][k];
	}
	if (k == 0)
		return 1;
	else if (cur_index == k) {
		long long res = 1;
		for (int i = 1; i <= k; ++i)
			res *= power[i - 1];
		min_list[cur_index][k] = res;
		max_list[cur_index][k] = res;
		return res;
	}
	else {
		if (cur_index == len + 1) {
			long long res = _inf;
			for (int i = len; i >= k; i--)
				res = max(res, max_power(i, max_list, min_list, power, len, k, d, 0));
			return res;
		}
		else {
			if (flag == 0) {
				long long res = _inf;
				int cur = power[cur_index - 1];
				for (int i = cur_index - 1; i >= cur_index - d && i >= k-1; i--) {
					res = max(res, cur*max_power(i, max_list, min_list, power, len, k - 1, d, cur < 0));
				}
				max_list[cur_index][k] = res;
				return res;
			}
			if (flag == 1) {
				long long res = inf;
				int cur = power[cur_index - 1];
				for (int i = cur_index - 1; i >= cur_index - d && i >= k-1; i--) {
					res = min(res, cur*max_power(i, max_list, min_list, power, len, k - 1, d, cur >= 0));
				}
				max_list[cur_index][k] = res;
				return res;
			}

		}
	}
	return -1;
}
int main(int argc, char**argv) {
	int n;
	cin >> n;
	int*power = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> power[i];
	int k, d;
	cin >> k >> d;
	vector<vector<long long>> max_list, min_list;
	max_list.resize(n + 1);
	min_list.resize(n + 1);
	for (int i = 0; i < n + 1; ++i) {
		max_list[i].resize(k + 1);
		min_list[i].resize(k + 1);
		for (int j = 0; j < k + 1; ++j) {
			max_list[i][j] = inf;
			min_list[i][j] = inf;
		}
	}
	cout << max_power(n + 1, max_list, min_list, power, n, k, d, 0);
	system("pause");
	return 0;
}
//题目描述
//有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
//输入描述 :
//每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n(1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（ - 50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d(1 <= k <= 10, 1 <= d <= 50)。
//输出描述 :
//输出一行表示最大的乘积。
//示例1
//输入
//
//3
//7 4 7
//2 50
//输出
//
//49

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define inf LLONG_MAX
#define _inf LLONG_MIN
//求从index开始到结束的这段区间中的最小值和最大值，返回最小和最大由flag决定0，最大，1，最小
//max_list: max_list[i][j]表示以i结尾，选择j个人的最大值
//min_list: min_list[i][j]...

//以下递归算法超时
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
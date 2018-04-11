#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector<vector<int>>results;
int solve(vector<int>&costs, vector<int>&credits, int M, int idx)
{
	if (M < 0)
		return -1;
	if (M == 0)
		return 0;
	if (idx == costs.size() - 1)
		return M >= costs[idx] ? credits[idx] : 0;
	if (results[idx][M] >= 0)
		return results[idx][M];
	int res1 = 0;
	int res2 = solve(costs, credits, M, idx + 1);
	results[idx][M] = res2;
	if (M >= costs[idx])
	{
		res1 = solve(costs, credits, M - costs[idx], idx + 1);
		if (credits[idx] + res1 >= res2)
			results[idx][M] = res1 + credits[idx];
	}
	return results[idx][M];
}
int main()
{
	int M;
	cin >> M;
	cin.get();
	vector<int> credits;
	vector<int> costs;
	char c;
	int tmp;
	while ((c = cin.get()) != '\n')
	{
		cin.unget();
		cin >> tmp;
		costs.push_back(tmp);
	}
	for (int i = 0; i < costs.size(); ++i)
	{
		cin >> tmp;
		credits.push_back(tmp);
	}

	results = vector<vector<int>>(costs.size(), vector<int>(M + 1, -1));
	solve(costs, credits, M, 0);
	int cur = M;
	vector<int>use;
	for (int i = 0; i < costs.size() - 1; i++)
	{
		if (results[i][cur] == results[i + 1][cur])
		{
			if (credits[i] == credits[i + 1])
				use.push_back(i + 1);
			i++;
		}
		else if (results[i][cur] > results[i + 1][cur]) {
			use.push_back(i+1);
			cur -= costs[i];
		}
	}
	if (cur > costs[costs.size() - 1])
		use.push_back(costs.size() - 1);
	for (int i = 0; i < use.size() - 1; ++i)
		cout << use[i] << " ";
	cout << use[use.size() - 1];
	system("pause");
	return 0;
}
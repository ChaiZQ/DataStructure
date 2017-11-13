//17年校招笔试
//题目描述
//小青蛙有一天不小心落入了一个地下迷宫, 小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。为了让问题简单, 假设这是一个n*m的格子迷宫, 迷宫每个位置为0或者1, 0代表这个位置有障碍物, 小青蛙达到不了这个位置; 1代表小青蛙可以达到的位置。小青蛙初始在(0, 0)位置, 地下迷宫的出口在(0, m - 1)(保证这两个位置都是1, 并且保证一定有起点到终点可达的路径), 小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值, 向上爬一个单位距离需要消耗3个单位的体力值, 向下移动不消耗体力值, 当小青蛙的体力值等于0的时候还没有到达出口, 小青蛙将无法逃离迷宫。现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0, m - 1)位置)。
//输入描述 :
//输入包括n + 1行 :
//	第一行为三个整数n, m(3 <= m, n <= 10), P(1 <= P <= 100)
//	接下来的n行 :
//	每行m个0或者1, 以空格分隔
//	输出描述 :
//如果能逃离迷宫, 则输出一行体力消耗最小的路径, 输出格式见样例所示; 如果不能逃离迷宫, 则输出"Can not escape!"。 测试数据保证答案唯一

//测试数据
 //6 5 100
 //1 0 0 0 1
 //1 1 0 0 1
 //0 1 0 0 1
 //1 1 0 0 1
 //1 0 0 0 1
 //1 1 1 1 1
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//采用dijkstra算法
int main(int argc, char**argv) {
	int n, m, P;
	cin >> n >> m >> P;
	vector<vector<int>>a;
	vector<vector<int>>dis;
	vector<vector<int>>collected;
	vector<vector<pair<int, int>>>path;
	path.resize(n);
	collected.resize(n);
	dis.resize(n);
	a.resize(n);
	path.resize(n);
	for (int i = 0; i < n; ++i) {
		path[i].resize(m);
		a[i].resize(m);
		dis[i].resize(m);
		collected[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			path[i][j] = pair<int, int>(0, 0);
			dis[i][j] = 0x7fffffff;
			collected[i][j] = 0;
		}
	}
	dis[0][0] = 0;
	for (;;) {
		//find smalledt dis
		int min_dis = 0x7fffffff;
		pair<int, int>min_pair(-1, -1);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (!collected[i][j] && a[i][j])
					if (dis[i][j] < min_dis) {
						min_dis = dis[i][j];
						min_pair.first = i;
						min_pair.second = j;
						if (min_dis == 0)break;
					}
				if (min_dis == 0)break;
			}
		if (min_pair.first == -1 && min_pair.second == -1)
			break;
		collected[min_pair.first][min_pair.second] = 1;
		//neiboring

		int  i = min_pair.first;
		int j = min_pair.second;
		//down
		if (i + 1 < n)
			if (a[i + 1][j] && !collected[i + 1][j])
				if (dis[i + 1][j] > min_dis) {
					dis[i + 1][j] = min_dis;
					path[i + 1][j] = min_pair;
				}
		//left
		if (j - 1 >= 0)
			if (a[i][j - 1] && !collected[i][j - 1])
				if (dis[i][j - 1] > min_dis + 1) {
					dis[i][j - 1] = min_dis + 1;
					path[i][j - 1] = min_pair;
				}
		//right
		if (j + 1 < m)
			if (a[i][j + 1] && !collected[i][j + 1])
				if (dis[i][j + 1] > min_dis + 1) {
					dis[i][j + 1] = min_dis + 1;
					path[i][j + 1] = min_pair;
				}
		//up
		if (i - 1 >= 0)
			if (a[i - 1][j] && !collected[i - 1][j])
				if (dis[i - 1][j] > min_dis + 3) {
					dis[i - 1][j] = min_dis + 3;
					path[i - 1][j] = min_pair;
				}

	}
	if (dis[0][m - 1] > P)
		cout << "Can not escape!";
	else {
		stack<pair<int, int>> path_stack;
		pair<int, int> tmp(0, m - 1);
		while (!(tmp.first==0 &&tmp.second==0)) {
			path_stack.push(tmp);
			pair<int, int>tmp1 = path[tmp.first][tmp.second];
			tmp = tmp1;
		}
		cout << "[0,0]";
		while (!path_stack.empty()) {
			cout << ",[" << path_stack.top().first << "," << path_stack.top().second << "]";
			path_stack.pop();
		}
	}
	system("pause");
	return 0;
}
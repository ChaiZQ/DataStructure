//17��У�б���
//��Ŀ����
//С������һ�첻С��������һ�������Թ�, С����ϣ�����Լ���ʣ������ֵP������������Թ���Ϊ���������, ��������һ��n*m�ĸ����Թ�, �Թ�ÿ��λ��Ϊ0����1, 0�������λ�����ϰ���, С���ܴﵽ�������λ��; 1����С���ܿ��Դﵽ��λ�á�С���ܳ�ʼ��(0, 0)λ��, �����Թ��ĳ�����(0, m - 1)(��֤������λ�ö���1, ���ұ�֤һ������㵽�յ�ɴ��·��), С�������Թ���ˮƽ�ƶ�һ����λ������Ҫ����1������ֵ, ������һ����λ������Ҫ����3����λ������ֵ, �����ƶ�����������ֵ, ��С���ܵ�����ֵ����0��ʱ��û�е������, С���ܽ��޷������Թ���������Ҫ�����С���ܼ�����ܷ��ý�ʣ������ֵ�����Թ�(���ﵽ(0, m - 1)λ��)��
//�������� :
//�������n + 1�� :
//	��һ��Ϊ��������n, m(3 <= m, n <= 10), P(1 <= P <= 100)
//	��������n�� :
//	ÿ��m��0����1, �Կո�ָ�
//	������� :
//����������Թ�, �����һ������������С��·��, �����ʽ��������ʾ; ������������Թ�, �����"Can not escape!"�� �������ݱ�֤��Ψһ

//��������
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
//����dijkstra�㷨
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
#include <iostream>
#include <vector>
using namespace std;

//bool isPair(int* list, int len, int i, int j) {
//	if (j == i + 1)
//		return true;
//	if (j == len - 1 && i == 0)
//		return true;
//	int steps = 1;
//	if ((j - i) >= len / 2)
//		steps = -1;
//	bool res = true;
//	for (int cnt = i + steps; cnt != j; cnt += steps) {
//		if (cnt >= len)
//			cnt %= len;
//		if (cnt < 0)
//			cnt += len;
//		if (list[cnt] > list[i] || list[cnt] > list[j]) {
//			res = false;
//			break;
//		}
//	}
//	if (res == true) {
//		return true;
//	}
//	res = true;
//	for (int cnt = i - steps; cnt != j; cnt -= steps) {
//		if (cnt >= len)
//			cnt %= len;
//		if (cnt < 0)
//			cnt += len;
//		if (list[cnt] > list[i] || list[cnt] > list[j]) {
//			res = false;
//			break;
//		}
//	}
//	if (res == true) {
//		return true;
//	}
//	return false;
//}
//
//int main(int argc, char**argv) {
//	int len;
//	cin >> len;
//	int*list = new int[len];
//	for (int i = 0; i < len; ++i) {
//		cin >> list[i];
//	}
//	int cnt = 0;
//	for (int i = 0; i < len - 1; ++i)
//		for (int j = i + 1; j < len; ++j)
//		{
//			if (isPair(list, len, i, j))
//				cnt++;
//		}
//	cout << cnt;
//	system("pause");
//	return 0;
//}
void testFunc(vector<vector<int>>& vec, vector<int>& vec2) {
	vec.push_back(vec2);
}
int main(int argc, char**arggv) {

	vector<vector<int> > vec1;
	vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);
	testFunc(vec1, vec2);
	testFunc(vec1, vec2);
	vec1.push_back(vec2);
	vec2.clear();
	for (int i = 0; i < vec1.size(); ++i)
		for (int j = 0; j < vec1[i].size(); ++j)
			j != vec1[i].size()-1 ? cout << vec1[i][j] << " " : cout << vec1[i][j] << endl;
	system("pause");
}
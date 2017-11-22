//题目描述
//小易喜欢的单词具有以下特性：
//1.单词每个字母都是大写字母
//2.单词没有连续相等的字母
//3.单词没有形如“xyxy”(这里的x，y指的都是字母，并且可以相同)这样的子序列，子序列可能不连续。
//例如：
//小易不喜欢"ABBA"，因为这里有两个连续的'B'
//小易不喜欢"THETXH"，因为这里包含子序列"THTH"
//小易不喜欢"ABACADA"，因为这里包含子序列"AAAA"
//小易喜欢"A", "ABA"和"ABCBA"这些单词
//给你一个单词，你要回答小易是否会喜欢这个单词。
//输入描述 :
//输入为一个字符串，都由大写字母组成，长度小于100
//输出描述 :
//如果小易喜欢输出"Likes", 不喜欢输出"Dislikes"

//测试
//ZYNXUDIJQFJWZAVMLROCMBGVKVTSEAZHPH

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char**argv) {
	string str;
	cin >> str;
	vector<vector<int>> alpha_pos;
	alpha_pos.resize(26);
	bool res = true;
	for (int i = 0; i < str.length(); ++i) {
		char alpha = str[i];
		if (alpha<'A' || alpha>'Z') {
			res = false;
			break;
		}
		if (i > 0 && str[i] == str[i - 1]) {
			res = false;
			break;
		}
		alpha_pos[alpha - 'A'].push_back(i);
		if (alpha_pos[alpha - 'A'].size() >= 4) {
			res = false;
			break;
		}
	}
	if (res != false) {
		for (int i = 0; i < alpha_pos.size(); ++i) {
			if (alpha_pos[i].size() < 2)
				continue;
			int p1 = *(alpha_pos[i].begin());
			int p2 = *(alpha_pos[i].end() - 1);
			int p_m = -1;
			if (alpha_pos[i].size() == 3)
				p_m = alpha_pos[i][1];
			for (int j = i + 1; j < alpha_pos.size(); ++j) {
				if (alpha_pos[j].size() < 2)
					continue;
				int p3 = *(alpha_pos[j].begin());
				int p4 = *(alpha_pos[j].end() - 1);
				if ((p3<p1&&p4>p1) || (p3<p2&&p4>p2) || (p3<p_m&&p4>p_m)) {
					res = false;
					break;
				}
			}
			if (res == false)
				break;
		}
	}
	if (res == false)
		cout << "Dislikes";
	else
		cout << "Likes";
	system("pause");
	return 0;
}
//��Ŀ����
//С��ϲ���ĵ��ʾ����������ԣ�
//1.����ÿ����ĸ���Ǵ�д��ĸ
//2.����û��������ȵ���ĸ
//3.����û�����硰xyxy��(�����x��yָ�Ķ�����ĸ�����ҿ�����ͬ)�����������У������п��ܲ�������
//���磺
//С�ײ�ϲ��"ABBA"����Ϊ����������������'B'
//С�ײ�ϲ��"THETXH"����Ϊ�������������"THTH"
//С�ײ�ϲ��"ABACADA"����Ϊ�������������"AAAA"
//С��ϲ��"A", "ABA"��"ABCBA"��Щ����
//����һ�����ʣ���Ҫ�ش�С���Ƿ��ϲ��������ʡ�
//�������� :
//����Ϊһ���ַ��������ɴ�д��ĸ��ɣ�����С��100
//������� :
//���С��ϲ�����"Likes", ��ϲ�����"Dislikes"

//����
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
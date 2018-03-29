#include <iostream>
#include <vector>
using namespace std;
//
//��ס��������õ�����һ���Ǵ���low����high�У����Բ�Ҫʹ��mid������һ��Ʈ��������ֵ
//ע��㣺1. ��ʱ����low����ʱ����right��2. �Ƚ��ж��к�ʱ���Ⱥţ���ʱ������
int main(int argc, char**argv) {
	vector<int> list;
	list.push_back(1);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(6);
	list.push_back(7);
	list.push_back(9);
	list.push_back(10);
	list.push_back(10);
	list.push_back(11);
	list.push_back(11);
	int target = 6;
	int pos = 0;
	int low = 0, high = list.size()-1;
	while (low <= high) {
		pos = (low + high) / 2;
		if (list[pos] >= target) {
			high = pos-1;
		}
		else if (list[pos] < target) {
			low = pos + 1;
		}
	}
	std::cout << "target: " << target << " Pos: " << high << endl;


	system("pause");
	return 0;
}
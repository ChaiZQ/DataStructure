//���ӣ�https://www.nowcoder.com/questionTerminal/876e3c5fcfa5469f8376370d5de87c06
//��Դ��ţ����
//
//С����������һ��������Ϸ��С�׸���һϵ�е�������������ʹ����Щ��������Ϸ��ÿ��С�׻�����˵һ�����ֳ�����Ȼ������Ҫ����һϵ��������ѡȡһ���ֳ��������ǵĺ͵���С����˵�����֡� ���磺 ���{ 2,1,2,7 }�����е�һϵ������С��˵��������11.����Եõ�����2 + 2 + 7 = 11.�����Ƥ��С������㣬��˵��������6����ô��û�а취ƴ�ճ���Ϊ6 ����С�׸���n�����������ҳ��޷���n������ѡȡ������͵������е���С����
//�������� :
//
//�����һ��Ϊ���ָ���n(n �� 20)
//�ڶ���Ϊn����xi (1 �� xi �� 100000)

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char**argv) {
	int n;
	cin >> n;
	int*list = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> list[i];
	sort(list, list + n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (list[i] > sum + 1)
			break;
		else {
			sum += list[i];
		}
	}
	cout << sum + 1;

	delete list;
	return 0;
}
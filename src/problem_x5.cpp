//ʹ�õݹ����ȫ����
//�������麬��n��Ԫ�أ�����ȡ�����е�ÿһ��Ԫ����һ��ͷԪ�أ�Ȼ��ȫ���г������г���һ��Ԫ��֮�������Ԫ�أ������ʹﵽ�˶�����������Ԫ�ؽ���ȫ���еĵ�Ŀ�ġ�����仰�����ص㣡��
//
//���ԣ�����n�����������n������ȫ����

#include<iostream>
using namespace std;
void swap(int*list, int i, int j) {
	int tmp = *(list + i);
	*(list + i) = *(list + j);
	*(list + j) = tmp;
}
//�������Ϊlen��������a��ȫ����
void full_permuation(int*a,int len,int start) {
	if (start==len-1) {
		for (int i = 0; i < len; ++i)
			cout << a[i] << " ";
		cout << endl;
		return;
	}

	for (int i = start; i < len; ++i) {
		//do swap
		swap(a,start, i);
		full_permuation(a, len ,start+1);
		swap(a,i, start);
	}
}
int main(int argc, char**argv) {
	int n;
	cin >> n;
	int*a = new int[n];
	for (int i = 0; i < n; ++i)
		a[i] = i+1;
	full_permuation(a, n, 0);
	system("pause");
	return 0;
}
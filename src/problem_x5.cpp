//使用递归进行全排列
//假设数组含有n个元素，则提取数组中的每一个元素做一次头元素，然后全排列除数组中除第一个元素之外的所有元素，这样就达到了对数组中所有元素进行全排列的得目的。【这句话才是重点！】
//
//测试，输入n个数，输出这n个数的全排列

#include<iostream>
using namespace std;
void swap(int*list, int i, int j) {
	int tmp = *(list + i);
	*(list + i) = *(list + j);
	*(list + j) = tmp;
}
//输出长度为len，的数组a的全排列
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
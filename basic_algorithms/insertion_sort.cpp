#include "iostream"
void swap(int list[], int k, int m)
{
	int tmp = list[k];
	list[k] = list[m];
	list[m] = tmp;
}

void insertion_sort(int* list, int len)
{
	//注意第一层循环可以不从0开始
	for(int i=1;i<len;++i)
	{
		int ref=list[i];
		int j = i;
		for(; j > 0 && list[j-1] > ref; j--)//只要满足条件，就移位
			list[j]=list[j-1];
		list[j]=ref;
	}
}

using namespace std;
int main(int argc, char**argv)
{
	int l[11] = { 4,5,1,8,0,2,7,3,11,4,4 };
	insertion_sort(l, 11);

	for (int i = 0; i < 11; ++i)
		cout << l[i] << ',';
	cout << endl;

	getchar();
	return 0;
}
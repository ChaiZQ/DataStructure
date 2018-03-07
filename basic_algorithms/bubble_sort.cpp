#include "iostream"
void swap(int list[], int k, int m)
{
	int tmp = list[k];
	list[k] = list[m];
	list[m] = tmp;
}

void bubble_sort(int* list, int len)
{
	for(int i=0;i<len;++i)
	{
		 for(int j=len-1;j>i;--j)
		 {
			 if (list[j] < list[j - 1])
				 swap(list, j, j - 1);
		 }
	}
}

using namespace std;
int main(int argc, char**argv)
{
	int l[11] = { 4,5,1,8,0,2,7,3,11,4,4 };
	bubble_sort(l, 11);

	for (int i = 0; i < 11; ++i)
		cout << l[i] << ',';
	cout << endl;

	getchar();
	return 0;
}
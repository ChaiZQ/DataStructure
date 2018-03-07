#include "iostream"
void swap(int list[], int k, int m)
{
	int tmp = list[k];
	list[k] = list[m];
	list[m] = tmp;
}

#define max_size 100 
void msort(int*list, int lo, int hi)
{
	if(lo==hi)
		return;
	int mid=(lo+hi)/2;
	
	msort(list,lo,mid);
	msort(list,mid+1,hi);
	
	//do merge
	//需要借助中间数组
	int tmp[max_size];
	int i=lo,j=mid+1;
	int cnt=0;
	while(i<=mid && j <=hi)
	{
		if(list[i]<list[j])
		{
			tmp[cnt++]=list[i++];
		}
		else
		{
			tmp[cnt++]=list[j++];
		}
	}
	while(i<=mid)
	{
		tmp[cnt++]=list[i++];
	}
	while(j<=hi)
	{
		tmp[cnt++]=list[j++];
	}
	for(int k=lo;k<=hi;k++)
	{
		list[k]=tmp[k-lo];
	}
}
void merge_sort(int* list, int len)
{
	msort(list,0,len-1);
}

using namespace std;
int main(int argc, char**argv)
{
	int l[11] = { 4,5,1,8,0,2,7,3,11,4,4 };
	merge_sort(l, 11);

	for (int i = 0; i < 11; ++i)
		cout << l[i] << ',';
	cout << endl;

	getchar();
	return 0;
}
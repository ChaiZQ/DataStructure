#include "iostream"
void swap(int list[], int k, int m)
{
	int tmp = list[k];
	list[k] = list[m];
	list[m] = tmp;
}

////某网络版本,注意等号！
//void qsort(int list[], int lo, int hi)
//{
//	if (lo < hi) {
//		int pivot = list[lo];
//		int i = lo;
//		int j = hi;
//		while (i < j)
//		{
//			while (i < j && list[j] >= pivot)
//				j--;
//			while (i<j && list[i] <= pivot)
//				i++;
//			if (i < j)
//			{
//				swap(list, i, j);
//			}
//		}
//		swap(list, lo, i);
//		qsort(list, lo, i - 1);
//		qsort(list, i+1, hi);
//	}
//}

////数据结构与算法分析版本，注意内循环的条件！！ //有问题！
//void qsort(int list[], int lo, int hi)
//{
//	int pivot = list[hi];
//	if (lo < hi) {
//		int i = lo;
//		int j = hi-1;
//		while (1)
//		{
//			while (list[j] >= pivot) j--;
//			while (list[i] <= pivot) i++;
//
//			if (i < j)
//				swap(list, i, j);
//			else
//				break;
//		}
//		swap(list, hi, i);
//		qsort(list, lo, i-1);
//		qsort(list, i+1, hi);
//	}
//}

//小甲鱼版本，注意等号, 注意次序！
void qsort(int list[], int lo, int hi)
{
	if (lo < hi) {
		int pivot = list[lo];
		int i = lo;
		int j = hi;
		while (i < j)
		{
			while (i < j && list[j] >= pivot)
			{
				j--;
			}
			swap(list, i, j);
			while (i < j && list[i] <= pivot)
			{
				i++;
			}
			swap(list, i, j);
		}
		qsort(list, lo, i-1);
		qsort(list, i+1, hi);
	}
}


////deng junhui版本，类似于小甲鱼升级版本, 记住这个版本！
//void qsort(int list[], int lo, int hi)
//{
//	if (lo < hi)
//	{
//		int pivot = list[lo];
//		int i = lo;
//		int j = hi;
//		//i和j处的位置交替空闲！
//		while (i < j)
//		{
//			while (i < j&&list[j] >= pivot) j--;
//			list[i] = list[j];
//			while (i < j&&list[i] <= pivot) i++;
//			list[j] = list[i];
//		}
//      //这个时候i和j相遇，相等，把这个值附成pivot
//		list[i] = pivot;
//
//		qsort(list, lo, i - 1);
//		qsort(list, i + 1, hi);
//	}
//}

void quickSort(int list[], int len)
{
	qsort(list, 0, len-1);
}


using namespace std;
int main(int argc, char**argv)
{
	int l[11] = { 4,5,1,8,0,2,7,3,11,4,4 };
	quickSort(l, 11);

	for (int i = 0; i < 11; ++i)
		cout << l[i] << ',';
	cout << endl;

	getchar();
	return 0;
}
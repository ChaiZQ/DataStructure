#include "iostream"
void swap(int list[], int k, int m)
{
	int tmp = list[k];
	list[k] = list[m];
	list[m] = tmp;
}

////ĳ����汾,ע��Ⱥţ�
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

////���ݽṹ���㷨�����汾��ע����ѭ������������ //�����⣡
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

//С����汾��ע��Ⱥ�, ע�����
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


////deng junhui�汾��������С���������汾, ��ס����汾��
//void qsort(int list[], int lo, int hi)
//{
//	if (lo < hi)
//	{
//		int pivot = list[lo];
//		int i = lo;
//		int j = hi;
//		//i��j����λ�ý�����У�
//		while (i < j)
//		{
//			while (i < j&&list[j] >= pivot) j--;
//			list[i] = list[j];
//			while (i < j&&list[i] <= pivot) i++;
//			list[j] = list[i];
//		}
//      //���ʱ��i��j��������ȣ������ֵ����pivot
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
# Sorting Note

###  Quick Sort

有很多变种，但按照“小甲鱼”或者“清华-邓俊辉”版本最容易理解！

按照“邓俊辉”版本的解释！快排的三个特点！

1. L<=pivot<=G; 
2. U=[lo,hi];
3. [lo]和[hi]交替空闲！

尤其是第3点。

先上小甲鱼的初级版本代码

```c++
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
```



邓版本优化交换的次数

```c++
//deng junhui版本，类似于小甲鱼升级版本, 记住这个版本！
void qsort(int list[], int lo, int hi)
{
	if (lo < hi)
	{
		int pivot = list[lo];
		int i = lo;
		int j = hi;
		//i和j处的位置交替空闲！
		while (i < j)
		{
			while (i < j&&list[j] >= pivot) j--;
			list[i] = list[j];
			while (i < j&&list[i] <= pivot) i++;
			list[j] = list[i];
		}
      //这个时候i和j相遇，相等，把这个值附成pivot
		list[i] = pivot;

		qsort(list, lo, i - 1);
		qsort(list, i + 1, hi);
	}
}
```



### Merge sort

要点

- 合并的时候要借助中间数组，因此效率会降低。





### Bubble sort

要点

- 相邻元素间作比较



### Insertion sort

要点

- 每趟是保证前i个元素有序
- 故第一层循环取一个新元素（为此，可以不从0开始取）
- 内层循环如果前面的项与新元素不满足条件，则移位！
- 最后再给腾出的位置赋值即可！
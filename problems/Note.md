# Problems

## 京东-保卫方案

## 题目描述

战争游戏的至关重要环节就要到来了，这次的结果将决定王国的生死存亡，小B负责首都的防卫工作。首都位于一个四面环山的盆地中，周围的n个小山构成一个环，作为预警措施，小B计划在每个小山上设置一个观察哨，日夜不停的瞭望周围发生的情况。 一旦发生外地入侵事件，山顶上的岗哨将点燃烽烟，若两个岗哨所在的山峰之间没有更高的山峰遮挡且两者之间有相连通路，则岗哨可以观察到另一个山峰上的烽烟是否点燃。由于小山处于环上，任意两个小山之间存在两个不同的连接通路。满足上述不遮挡的条件下，一座山峰上岗哨点燃的烽烟至少可以通过一条通路被另一端观察到。对于任意相邻的岗哨，一端的岗哨一定可以发现一端点燃的烽烟。 小B设计的这种保卫方案的一个重要特性是能够观测到对方烽烟的岗哨对的数量，她希望你能够帮她解决这个问题。

## 输入描述:

```
输入中有多组测试数据，每一组测试数据的第一行为一个整数n(3<=n<=10^6),为首都周围的小山数量，第二行为n个整数，依次表示为小山的高度h（1<=h<=10^9）.
```

## 输出描述:

```
对每组测试数据，在单独的一行中输出能相互观察到的岗哨的对数。
```

示例1

## 输入

```
5
1 2 4 5 3
```

## 输出

```
7
```

## 思路

我们可以用单调递减栈来做，以题中的例子为例 1 2 4 5 3

先考虑没有连续重复元素的情况，接着说有重复元素的情况 
先循环移位，让最大值5作为第一个元素（why？），那么这个时候，数组为 5 3 1 2 4。

设结果为res=0; 
由于栈是单调递归栈，那么5,3,1 依次入栈。此时栈顶元素是1。接下来要入栈的是2。2大于栈顶元素1，那么栈顶元素1的左边（3），右边（2）。那么1是可以看到3和2的，有两对。res=2

1出栈，此时栈顶元素为3,2小于3。所以2进栈。此时栈顶元素为2。接下来要4要进栈，4大于栈顶元素2。那么栈顶元素2可以看到左边(3)右边(4)。res=2+2=4。2出栈

同理，3出栈，4进栈。res=4+2=6。 
此时，栈里面的元素只有4和5。作为一对。res=6+1=7。

有重复元素的情况下，假设 3,1(连续n个1) ,4。这n个1都能看到3和4有2*n个，而且这个n个1是可以互相看到对方，所以有Cn2个。所以对数为 2*n+n(n-1)/2。两种元素的情况下 1(t1个1)、2(t2个2)，对数为t1\*t2+t1\*(t1-1)/2+t2*(t2-1)/2。
## 使用异或交换两个整数
使用该种方法不需要申请额外的空间
```
a = a ^ b;
b = a ^ b; //a ^ b ^ b = a ^ 0 = a;
a = a ^ b;
```

## 最最常出现的面试题：一个整型数组里除了N个数字之外，其他的数字都出现了两次，找出这N个数字；
- 题目：（LeetCode 中通过率最高的一道题） Single Number: Given an array of integers, every element appears twice except for one. Find that single one. Note:Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 思路： 拿到这个题目，本能的你会使用排序（数字文字我们常常需要排序），排序后可以来判断是否数字成对出现，思路很明显，但是排序的算法上限是 O(nlogn)，不符合题目要求；

```
A ^ B ^ C ^ B ^ C ^ D ^ A
= A ^ A ^ B ^ B ^ C ^ C ^ D
= 0 ^ 0 ^ 0 ^ D
= 0 ^ D
= D

```
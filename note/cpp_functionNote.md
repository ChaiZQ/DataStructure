# Function Note

### reverse

```c++
template<class BidirectionalIterator>
   void reverse(
      BidirectionalIterator _First, 
      BidirectionalIterator _Last
   );
```



- 对vector

  ```c++
  reverse(vec.begin(),vec.end())
  ```


### sort

- 自带的equal_to<Type>、not_equal_to<Type>、greater<Type>、greater_equal<Type>、less<Type>、less_equal<Type>

- 用在数组中时，注意索引

  ```c
  int a[100];
  ...
  sort(a,a+100+1);//注意是101而不是100!!!!
  ```

### memset

void *memset(void *s,int c,size_t n)

- 对从s开始的n个字节赋值为c，注意是n个字节，而不是n个指针长度！
- 注意是给每个字节赋值，而不是给每个指针指向的对象赋值！



### stl中的multimap

基本操作：

插入insert()，

与 map 类似，multimap 具备两个版本重载的 find()成员函数：

```c
iterator find(const key_type& k);
const_iterator find(const key_type& k) const;
```

count(k) 成员函数返回与给定键关联的值得数量。下面的例子报告了有多少个与键 “213.108.96.7” 关联的值：

```
cout<<dns.count("213.108.96.7") //output: 2
            <<" elements associated"<<endl;
```

为了存取 multimap 中的多个值，使用 equal_range()、lower_bound()和 upper_bound()成员函数：
equal_range(k)：该函数查找所有与 k 关联的值。返回迭代指针的 pair，它标记开始和结束范围。下面的例子显示所有与键“213.108.96.7”关联的值：

```c
typedef multimap <string, string>::const_iterator CIT;
typedef pair<CIT, CIT> Range;
Range range=dns.equal_range("213.108.96.7");
for(CIT i=range.first; i!=range.second; ++i)
cout << i->second << endl; //output: cpluspluszone.com
// cppzone.com
```

lower_bound() 和 upper_bound()：lower_bound(k) 查找第一个与键 k 关联的值，而 upper_bound(k) 是查找第一个键值比 k 大的元素。下面的例子示范用 upper_bound()来定位第一个其键值大于“213.108.96.7”的元素。通常，当键是一个字符串时，会有一个词典编纂比较：

```c
dns.insert(make_pair("219.108.96.70", "pythonzone.com"));
CIT cit=dns.upper_bound("213.108.96.7");
if (cit!=dns.end()) //found anything?
cout<<cit->second<<endl; //display: pythonzone.com
```

如果你想显示其后所有的值，可以用下面这样的循环：

```c
// 插入有相同键的多个值
dns.insert(make_pair("219.108.96.70","pythonzone.com"));
dns.insert(make_pair("219.108.96.70","python-zone.com"));
// 获得第一个值的迭代指针
CIT cit=dns.upper_bound("213.108.96.7");
// 输出: pythonzone.com，python-zone.com
while(cit!=dns.end())
{
cout<<cit->second<<endl;
++cit;
}
```
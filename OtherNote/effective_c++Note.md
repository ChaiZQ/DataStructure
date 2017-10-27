# 		Effective C ++

## C-1

### 1. 尽量以const, enum, inline替换#define

- 定义常量指针

  若要在头文件内定义一个常量字符串，必须写const两次

  ```c++
  const char* const authorname = "Scott"
  ```

- 类中静态常量不能在声明的时候赋初值，其他非静态成员可以

### 2. 尽可能使用const

- 注意以下差异，区别仅在于 const在*的左边还是右边

```c++
char greeting[]="hello";
char* p=greeting;
const char* p =greeting;
char* const p = greeting;
char const* p = greeting;
const char* const p = greeting;
```

- 注意以下差别

  ```c++
  //相当于T* const
  const std::vector<int>::iterator iter = vec.begin();
  //相当于 const T*
  std::vector<int>::const_iterator cIter = vec.begin();
  ```

  ​




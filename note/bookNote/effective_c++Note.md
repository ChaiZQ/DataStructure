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

  ```c
  char greeting[]="hello";
  char* p=greeting;
  const char* p =greeting;
  char* const p = greeting;
  char const* p = greeting;
  const char* const p = greeting;
  ```

  ​


- 注意以下差别

  ```c++
  //相当于T* const
  const std::vector<int>::iterator iter = vec.begin();
  //相当于 const T*
  std::vector<int>::const_iterator cIter = vec.begin();
  ```


### 3. 编译器会自动为类创建的函数 

- default构造，copy构造，copy assignment 操作符以及析构函数。4种。
- 唯有以上四种函数被需要（被调用）时，才会被编译器生成出来。
- 当类成员中出现了**引用**时，编译器将拒绝编译copy构造，copy assignment等语句。
- 当类成员中出现了**const**变量时，编译器也拒绝编译copy构造，copy assignment等语句，因为，不知道如何给__const__变量赋值。


### 4.  声明析构函数为虚函数

- 何时应该声明，何时不建议声明
- 最好别继承stl中的类，类似的理由

### 5. 绝对不要在构造和析构的过程中调用virtual函数 

### 6. assignment操作符返回一个reference to *this

### 7. std::auto_ptr

- copy assignment或者copy 构造之后，原有的ptr被置为NULL，新的ptr成为对象的唯一占有者。
- 与之对比，std::tr1::shared_ptr
- ​

## C-5

### 1. 转型

四种新式转型

```c++
const_cast<T>
dynamic_cast<T>
reinterpret_cast<T>
static_cast<T>
```

![pic1](D:\Documents\GitHub\DataStructure\note\bookNote\pic1.png)

- 单一对象可能拥有一个以上的地址，例如以base\*指向它时的地址和以Derived\*指向它时的地址（C, Java，C#)不可能发生这种事，但c++可能。
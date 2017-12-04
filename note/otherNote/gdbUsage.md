## 生成调试信息

一般来说GDB主要调试的是C/C++的程序。要调试C/C++的程序，首先在编译时，我们必须要把调试信息加到可执行文件中。使用编译器（cc/gcc/g++）的 -g 参数可以做到这一点。如：

gcc -g hello.c -o hello

g++ -g hello.cpp -o hello

如果没有-g，你将看不见程序的函数名、变量名，所代替的全是运行时的内存地址。当你用-g把调试信息加入之后，并成功编译目标代码以后，让我们来看看如何用gdb来调试他。

## 程序运行参数

set args 可指定运行时参数。（如：set args 10 20 30 40 50 ）

show args 命令可以查看设置好的运行参数。

run (r) 启动程序

不指定运行参数 r

指定运行参数r 10 20 30 40 50

##  工作目录

cd 相当于shell的cd命令。

pwd 显示当前的所在目录。



## 程序输入输出

info terminal 显示你程序用到的终端的模式。

使用重定向控制程序输出。如：run > outfile

tty命令可以设置输入输出使用的终端设备。如：tty /dev/tty1



## 断点

break 设置断点，可以简写为b

b 10 设置断点，在源程序第10行

b func 设置断点，在func函数入口处

##多文件设置断点

在进入指定函数时停住:

C++中可以使用class::function或function(type,type)格式来指定函数名。如果有名称空间，可以使用namespace::class::function或者function(type,type)格式来指定函数名。

break filename:linenum 
在源文件filename的linenum行处停住 
break filename:function 
在源文件filename的function函数的入口处停住

break class::function或function(type,type)

在类class的function函数的入口处停住

break namespace::class::function

在名称空间为namespace的类class的function函数的入口处停住



## 查询所有断点

info b



## 观察点

watch 为表达式（变量）expr设置一个观察点。当表达式值有变化时，马上停住程序。

rwatch 表达式（变量）expr被读时，停住程序。

awatch 表达式（变量）的值被读或被写时，停住程序。

info watchpoints 列出当前所设置了的所有观察点。

## 条件断点

一般来说，为断点设置一个条件，我们使用if关键词，后面跟其断点条件。并且，条件设置好后，我们可以用condition命令来修改断点的条件。并且，条件设置好后，我们可以用condition命令来修改断点的条件。（只有break 和 watch命令支持if，catch目前暂不支持if）。

设置一个条件断点

b test.c:8 if intValue == 5

condition 与break if类似，只是condition只能用在已存在的断点上

修改断点号为bnum的停止条件为expression

condition bnum expression

清楚断点号为bnum的停止条件

condition bnum

ignore 忽略停止条件几次

Ignore bnum count

表示忽略断点号为bnum的停止条件count次

## 维护停止点

clear 清除所有的已定义的停止点。

clear function 清除所有设置在函数上的停止点。

clear linenum 清除所有设置在指定行上的停止点。

clear filename:linenum 清除所有设置在指定文件：指定行上的停止点。

delete [breakpoints] [range...] 删除指定的断点，breakpoints为断点号。如果不指定断点号，则表示删除所有的断点。range 表示断点号的范围（如：3-7）。其简写命令为d。

比删除更好的一种方法是disable停止点，disable了的停止点，GDB不会删除，当你还需要时，enable即可，就好像回收站一样。

disable [breakpoints] [range...]

disable所指定的停止点，breakpoints为停止点号。如果什么都不指定，表示disable所有的停止点。简写命令是dis.

enable [breakpoints] [range...]

enable所指定的停止点，breakpoints为停止点号。

enable [breakpoints] once range…

enable所指定的停止点一次，当程序停止后，该停止点马上被GDB自动disable。

enable [breakpoints] delete range…

enable所指定的停止点一次，当程序停止后，该停止点马上被GDB自动删除。

## 为停止点设定运行命令

我们可以使用GDB提供的command命令来设置停止点的运行命令。也就是说，当运行的程序在被停止住时，我们可以让其自动运行一些别的命令，这很有利行自动化调试。对基于GDB的自动化调试是一个强大的支持。

commands [bnum]

… command-list …

end

为断点号bnum指写一个命令列表。当程序被该断点停住时，gdb会依次运行命令列表中的命令。

例如：

break foo if x>0

commands

printf “x is %d “,x

continue

end

断点设置在函数foo中，断点条件是x>0，如果程序被断住后，也就是，一旦x的值在foo函数中大于0，GDB会自动打印出x的值，并继续运行程序。

如果你要清除断点上的命令序列，那么只要简单的执行一下commands命令，并直接在打个end就行了。

## 调试代码

run 运行程序，可简写为r

next 单步跟踪，函数调用当作一条简单语句执行，可简写为n

step 单步跟踪，函数调进入被调用函数体内，可简写为s

finish 退出函数

until 在一个循环体内单步跟踪时，这个命令可以运行程序直到退出循环体,可简写为u。

continue 继续运行程序，可简写为c

stepi或si, nexti或ni 单步跟踪一条机器指令,一条程序代码有可能由数条机器指令完成，stepi和nexti可以单步执行机器指令。

info program 来查看程序的是否在运行，进程号，被暂停的原因。

## 查看运行时数据

print 打印变量、字符串、表达式等的值，可简写为p 
p count 打印count的值 
p cou1+cou2+cou3 打印表达式值

print接受一个表达式，GDB会根据当前的程序运行的数据来计算这个表达式，表达式可以是当前程序运行中的const常量、变量、函数等内容。但是GDB不能使用程序中定义的宏。

##  程序变量

在GDB中，你可以随时查看以下三种变量的值：

1、全局变量（所有文件可见的）

2、静态全局变量（当前文件可见的）

3、局部变量（当前Scope可见的）

如果你的局部变量和全局变量发生冲突（也就是重名），一般情况下是局部变量会隐藏全局变量，也就是说，如果一个全局变量和一个函数中的局部变量同名时，如果当前停止点在函数中，用print显示出的变量的值会是函数中的局部变量的值。如果此时你想查看全局变量的值时，你可以使用“::”操作符：

file::variable

function::variable

可以通过这种形式指定你所想查看的变量，是哪个文件中的或是哪个函数中的。例如，查看文件f2.c中的全局变量x的值：

p ‘f2.c’::x

当然，“::”操作符会和C++中的发生冲突，GDB能自动识别“::”是否C++的操作符，所以你不必担心在调试C++程序时会出现异常。

## 数组变量

有时候，你需要查看一段连续的内存空间的值。比如数组的一段，或是动态分配的数据的大小。你可以使用GDB的“@”操作符，“@”的左边是第一个内存的地址的值，“@”的右边则你你想查看内存的长度。例如，你的程序中有这样的语句：

int *array = (int *) malloc (len * sizeof (int));

于是，在GDB调试过程中，你可以以如下命令显示出这个动态数组的取值：

p *array@len

@的左边是数组的首地址的值，也就是变量array所指向的内容，右边则是数据的长度，其保存在变量len中。



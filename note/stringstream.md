# stringstream用法

 C++引入了ostringstream、istringstream、stringstream这三个类，要使用他们创建对象就必须包含sstream.h头文件。

istringstream类用于执行C++风格的串流的输入操作。 
ostringstream类用于执行C++风格的串流的输出操作。 
strstream类同时可以支持C++风格的串流的输入输出操作。

istringstream类是从istream和stringstreambase派生而来，ostringstream是从ostream和 stringstreambase派生而来， stringstream则是从iostream类和stringstreambase派生而来。

在多次转换中重复使用同一个stringstream（而不是每次都创建一个新的对象）对象最大的好处在于效率。stringstream对象的构造和析构函数通常是非常耗费CPU时间的。

设置精度，包含iomanip
常用 setfill，setw

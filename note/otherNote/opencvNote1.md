## 矩阵转置之后，存储方式是否改变？
初始化一个矩阵时，存储方式改变，对自己或其他矩阵赋值操作时，也会改变。
（意外发现，在ubuntu下，如果没有endl，cout的东西出不来）
## opencv 矩阵存储是按照行存储
elemSize: 矩阵中每一个元素的数据大小CV_8U:1,CV_8UC3:3,CV_16UC2:4。另有一个elemSize1表示矩阵中数据类型的大小，即elemSize/channels
## Mat::ptr模板
```
cv::Mat image = cv::Mat(400, 600, CV_8UC1); //宽400，长600
    uchar * data00 = image.ptr<uchar>(0);
    uchar * data10 = image.ptr<uchar>(1);
    uchar * data01 = image.ptr<uchar>(0)[1];
```
解释：

    定义了一个Mat变量image。@[]()
    data00是指向image第一行第一个元素的指针。
    data10是指向image第二行第一个元素的指针。
    data01是指向image第一行第二个元素的指针。
    
使用上面的代码举例：image有400行，有400*600个像素。假设现在你想得到第3行第42个像素的指针，如果你写成：
```
uchar * data = image.ptr<uchar>(3*image.cols + 41);
```
这样写是错误的，会出现上面的错误。你得到的不是第３行第４２个像素的指针，而是第（3×image.cols + 41）行第0个像素的指针，因为没有（3×image.cols + 41）行，所以没有这个指针，所以错误。
正确的写法：
```
uchar * data = image.ptr<uchar>(3)[41];
```
所以要注意这一点：如果程序可以正常编译，但是运行时出错，很有可能是你给指针赋值的时候，索引值溢出指定范围，指针乱指，导致程序跑偏，所以只有在运行时才能发现。
以下为错误的写法
```
cv::Mat image = cv::Mat(400, 600, CV_8UC3); //宽400，长600，３通道彩色图片
    uchar * data000 = image.ptr<uchar>(0);
    uchar * data100 = image.ptr<uchar>(1);
    uchar * data001 = image.ptr<uchar>(0)[1];
    uchar * data；
```

  应该写成
```
    cv::Mat image = cv::Mat(400, 600, CV_8UC3); //宽400，长600，３通道彩色图片
   cv::Vec3b * data000 = image.ptr<cv::Vec3b>(0);
    cv::Vec3b * data100 = image.ptr<cv::Vec3b>(1);
    cv::Vec3b * data001 = image.ptr<cv::Vec3b>(0)[1];
    cv::Vec3b * data
```
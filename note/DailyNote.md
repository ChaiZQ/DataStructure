# Daily Note

## 2017-10-30

- 判别式模型（discriminant model），生成式模型(generative model)的区别

  “马春鹏1.5.4”

- 学习了adaboost方法，对比了周志华，马春鹏，李航三个版本的推导方法，并没有看太懂。

- Bagging方法，随机森林方法。

- 初步看了stacking学习法，没看懂。k折交叉验证，用初级数据集产生次级数据集的方法

- python机器学习实战，决策树的代码熟悉

## 2017-10-31

- 比较了以下adaboost和gradient boost （GBDT)，其中的差异比较模糊

  > AdaBoost是通过提升错分数据点的权重来定位模型的不足而Gradient Boosting是通过算梯度（gradient）来定位模型的不足


### 2017-11-2

- logistic regresstion 公式推导！！尤其是costfunction的gradient，求gradient后形式很简单！以及python 实现



### 2018-3-5

- 看完了https://www.cnblogs.com/Y1Focus/p/6707121.html，需要反复多次的浏览增强记忆
- 看完了http://blog.csdn.net/charles_r_chiu/article/details/47858885，需反复多次浏览
- 调试object-detector （car detector）失败，一直报错，原因不明（已放弃）


### 2018-3-6

- 学习了RNN 模型。RNN循环神经网络，处理序列式的输入，实现信息的反复使用，（效果并不太好，所有的成果几乎都是RNN的变种LSTM，long short term），LSTM的变体GRU（gated recurrent unit) 将忘记门和输入门合成一个单一的更新门。

  http://blog.csdn.net/prom1201/article/details/52221822 

  ​


### 2018-3-9

- 一大类动态规划问题，任意面值无限使用时目标值的最小张数，有限使用时的最小张数，无限使用时目标的方法总数。

- 根据邻接矩阵建立有向图（多叉树）

- 最近公共祖先的编程思路，建立一个map，标记路径a上所有的点，然后在路径b上依次检查是否被标记过。若是简单的int型，可以直接使用vector代替map。

- 统计一个数二进制中1的个数的方法！

  ```c
  int cnt=0;
  while(dif!=0){
      dif=dif&(dif-1);
      cnt++;
  }             //统计一个整数dif含有多少个1；

  ```

### 2018-3-11

- leetcode 376 wiggle subsequence

- 透彻理解二分搜索，掌握各种细节 http://www.cnblogs.com/luoxn28/p/5767571.html

  https://www.cnblogs.com/bofengyu/p/6761389.html


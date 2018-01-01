# Learning Method

### Eric Branchmann : Uncertainty-Driven

- 使用AC forest，与其引用的参考文献【2】(learning 6D)的结构类似
- 1中说到能处理multiple objects是指同一种物体的多个实例？
- 2017-11-1:  在网页http://blog.sina.com.cn/s/blog_6e3160cb0100t2vx.html中看到了对auto-context的理解，颇有启发！
- 17-11-28：object coordinate 的方法称为Vitruvian Manifold ，这个在【2】（learning 6D）中开篇就提到了，引用的参考文献为【26】（The Vitruvian Manifold ）
- 17-11-28：学习一下高斯混合模型 ，学习一下mean shift！这个要深刻了解的话必须系统的学习马尔科夫随机场，并熟悉EM过程。
- 17-11-28：提到了auto-context对于RGB-D并没有提高，也就是只对RGB有用
- 17-11-28：找到了training data的size，取angular distance最小15度，这样下来大概相当于15%的size。
- 17-12-20: auto-context的介绍中提到了文献【12】（geodesic forests）应该对熟悉aoto-context框架有帮助，附带的【11】也可以看一下,【11】这篇文章把auto-context用到了multi-dimmensional output 上面，也就是这篇文章用到的,提到了某个smoothing环节对多维输出的性能很关键，并将在后文中阐述这一点。
- 17-12-20: 文章还提到了一个特点即multi-object ransac，提到了该我文章的一个特点，其他的多物体识别方法都是在同一个坐标系下处理所有的点，而本文中却在各自的独立坐标系下（这一点需要结合代码的数据结构理解）
- 17-12-21: 提到ａｃ时，对比和【１２】的差别，【１２】用到的是geodesic filter, 而本文用到median filter。

### Eric Branchmann : learning 6D（附加supplementary material）

- 使用了“Decision forests for CV and ...”的标准化training procedure
- 使用了【24】“Scene Coordinate Regression Forests ”中的feature
- 17-11-28：object coord，离散化成了125个。
- 17-10-30： 发现3.2节中的“we train a stack of forests”，是否是用了stacking算法？是的
- 17-11-29：读了suple，发现其训练数据有real data和synthetic两种。（暂时没有找到使用real时的数量）
- 17-11-29： 提到了linemod达到paper性能的关键是两步outlier removal
- 17-12-22： 重新读了训练部分，训练random forest的步骤是，先根据quantized coordinate去生成forest结构（训练用的pixel是随机采样的）。然后再把所有的object上的coord push到这个tree中，记录每个pixel到达的leaf，记录这个leaf中所有连续的coord和object class。根据leaf的这些信息计算probability。


### Shotton： Scene Coordinate Regression Forests

- 只使用简单的深度图和RGB图的比较特征
- 建立了scene coordinate regression forest
- 也是参考了“Decision forests for CV and...” 
- 在生成叶节点后，每个叶节点的模式通过mean shift算法生成,见mode fitting那一节。
- 给出了feature计算的两个公式，称作“feature response functions”（并没有太看懂）
- pixel的labels定义成scene world positions
- 2.4中theta包含哪些参数？？？？（2.1节介绍的时候定义了）

### Kontschieder: GeoF
- 17-12-21: 在decision forest models 部分，讲述了和传统CRF的差别，主要是在后验概率项中略去了一部分。
- 17-12-21： generalized geodesic distances 中的M(P)到底指什么？？ 后文中有提到可以用probability map来代替这个。
- 17-12-21： 可是如何incorporate geodesic distances as connectivity features within a classification forest?
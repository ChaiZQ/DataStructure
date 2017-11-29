# Learning Method

### Eric Branchmann : Uncertainty-Driven

- 使用AC forest，与其引用的参考文献【2】(learning 6D)的结构类似
- 1中说到能处理multiple objects是指同一种物体的多个实例？
- 2017-11-1:  在网页http://blog.sina.com.cn/s/blog_6e3160cb0100t2vx.html中看到了对auto-context的理解，颇有启发！
- 17-11-28：object coordinate 的方法称为Vitruvian Manifold ，这个在【2】（learning 6D）中开篇就提到了，引用的参考文献为【26】（The Vitruvian Manifold ）
- 17-11-28：学习一下高斯混合模型 ，学习一下mean shift！
- 17-11-28：提到了auto-context对于RGB-D并没有提高，也就是只对RGB有用
- 17-11-28：找到了training data的size，取angular distance最小15度，这样下来大概相当于15%的size。


### Eric Branchmann : learning 6D（附加supplementary material）

- 使用了“Decision forests for CV and ...”的标准化training procedure
- 使用了【24】“Scene Coordinate Regression Forests ”中的feature
- 17-11-28：object coord，离散化成了125个。
- 17-10-30： 发现3.2节中的“we train a stack of forests”，是否是用了stacking算法？是的
- 17-11-29：读了suple，发现其训练数据有real data和synthetic两种。（暂时没有找到使用real时的数量）
- 17-11-29： 提到了linemod达到paper性能的关键是两步outlier removal



### Shotton： Scene Coordinate Regression Forests

- 只使用简单的深度图和RGB图的比较特征
- 建立了scene coordinate regression forest
- 也是参考了“Decision forests for CV and...” 
- 在生成叶节点后，每个叶节点的模式通过mean shift算法生成
- 给出了feature计算的两个公式，称作“feature response functions”（并没有太看懂）
- pixel的labels定义成scene world positions
- 2.4中theta包含哪些参数？？？？（2.1节介绍的时候定义了）
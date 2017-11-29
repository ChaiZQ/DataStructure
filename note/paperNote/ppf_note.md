# PAPER READ NOTE



###  Drost: multi-modal ppf 

- 是使用intensity image提取边缘，再用range border 进行filtering
- 性能大大提升！


### Hinterstoisser： Going further

- 大小球策略：不是很好处理
- 一个flag防止重复投票


- 后处理才是关键！用于重新计算分数，最后几段的内容
- 在结果处理部分，提到了只用了上半球的特征，怎么做到的？



### Tolga Birdal： revisited

- 做了pre-segmentation，如何做的暂时不知道，但似乎这个很有用。
- 似乎通过Efficient Graph-Based Image Segmentation类似的方法做的segmentation，这是篇很著名的文献，引用广泛。



### Felzenszwalb： Efficient GB Seg

- http://blog.csdn.net/huixingshao/article/details/42642973，收藏在360
- http://blog.csdn.net/mao_kun/article/details/50576036  ~



### Changyun Choi： voting-based

- 对工业零件的优化，构造的特征很有想法！

### Eric Brachmann : Global hypothesis

- 提到了drost成功的main reason
- CRF model
- Random-forest
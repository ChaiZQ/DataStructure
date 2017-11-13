# 最短路径算法

### Dijkstra算法：单原最短路径算法

两种实现方法，第一种，每次都找与当前节点最近的节点，第二种，使用队列，不必每次找与当前节点最近的节点，直接操作当前节点的相邻节点。

- 定义

令G=(V,E)为一个带权有向网，S为已经找到的从v0出发的最短路径终点的集合，S的初始状态为空。

- 算法步骤

http://blog.csdn.net/u013071074/article/details/29582381

（1）首先遍历V-S，若arcs\[0\]\[i\]存在（即该点与源点相邻），设置其初始的最短距离dj为argc\[0\]\[i\]。

（2）在V-S中选择vj，使得其dj最小，那么vj的最短距离就是dj，令S=S∪{j}；

（3）修改从v0出发到集合V-S上任意点vk的最短距离，如果arcs\[j\]\[k\]存在，并且dj+arcs\[j\]\[k\]<dk, 则把dk赋值为dj+arcs\[j\]\[k\]；

（4）若V-S不为空，转到（2）。

- 伪代码

  ```c
  void ShortestPath_Dij(Vertex s){
    while(1) {
      V = 未收录顶点中dist最小着;
      collected[V]=true;
      for( V的每个邻接点W)
        if(collected[W]==false)
          if(dist[V]+E(V,W)<dist[W]){
            dist[W]=dist[V]+E(V,W);
            path[W]=V;
          }
    }
  }
  ```

  dist的初始化，源点的距离初始化为0，与源点相邻的初始化为边长，其他的一定要初始化为“无穷大！”，对int型，初始化为0x7fffffff，注意，这个数只能做比较，不能做计算，否则会溢出！

- code

```c++
/* Dijkstra算法求有向网g的下标为v0的顶点到其余顶点下标为v的最短路径P[v]及带权长度D[v] */   
/* P[v]的值为前驱顶点下标,D[v]表示v0到v的最短路径长度和 */   
void ShortestPath_DIJ(Graph *g, int v0, PathMatrix p[], ShortPathTable d[])  
{  
    int i, v, w, k;  
    EdgeType min;  
    bool final[MAX_VEX];    /* final[w]=1表示求得顶点V0至Vw的最短路径 */  
  
    //初始化数据  
    for (v = 0; v < g->vexNum; v++)  
    {  
        final[v] = false;      //全部顶点初始化为未知最短路径状态  
        d[v] = g->arc[v0][v];  //将与v0点有连线的顶点加上权值  
        p[v] = v0;             //初始化路径数组P为v0  
    }  
    d[v0] = 0;                //v0至v0的路径为0  
    final[v0] = true;         //v0∈S, v0至v0不需要求路径  
  
    //开始主循环，每次求得v0到某个v顶点的最短路径,并 加入v到集合S, 变量i没起啥作用啊？ 
    for (i = 0; i < g->vexNum; i++)  
    {  
        if (i == v0) continue;  
        min = INFINITY;  
        for (w = 0; w < g->vexNum; w++)    //寻找V-S中离v0最近的顶点  
        {  
            if (!final[w] && d[w] < min)  
            {  
                min = d[w];    //下标为w的顶点离v0更近  
                v = w;  
            }  
        }  
                //if (v == t) break;    //如果只查找到下标为t的某个顶点  
        final[v] = true;    //下标为k的顶点并入集合S,即将当前找到了最短路径的顶点标记为true  
  
        //更新当前最短路径及距离  
        for (w = 0; w < g->vexNum; w++)  
        {  
            //如果经过v顶点的路径比现在这条路径的长度短的话  
            if (!final[w] && (min + g->arc[v][w] < d[w]))  
            {  
                //说明找到了更短的路径，修改D[w]和P[w]  
                d[w] = min + g->arc[v][w];  
                p[w] = v;  
            }  
        }  
    }  
}  
```

```c
// 查找从源点v到终点u的路径,并输出  
void SearchPath(VertexType vex[], PathMatrix *prev,int v, int u)  
{  
    int que[MAX_VEX];  
    int tot = 0;  
    que[tot++] = u;  //终点u  
    int tmp = prev[u];   //到顶点下标u的路径上的上一个顶点下标  
    while(tmp != v)  
    {  
        que[tot++] = tmp;  
        tmp = prev[tmp];   //到顶点下标tmp的路径上的上一个顶点下标  
    }  
    que[tot] = v;  
    for(int i = tot; i >= 0; --i)  
        if(i != 0)  
            printf("%c -> ", vex[que[i]]);  
        else  
            printf("%c", vex[que[i]]);  
}  
```

- 时间复杂度

  外循环|V|次，循环中，搜索最小的距离（一般的算法，|V|次，使用最小堆log|V|），操作边，每条边只操作一次，|E|。

### Floyd算法： 多源最短路径算法

#### 思想

从任意点A到任意点B的最短路径就两种可能，一是直径从A到B，2是从A经过若干个节点到B。假设dist(A,B)表示A到B的最短路径，则对每一个节点K，都应该有dist(A,K)+dist(K,B)<=dist(A,B)。

所以代码非常简洁，只需要注意一点，外循环是k，用来检查的节点！

```c
for (int k=0; k<n; ++k)
  for (int i=0; i<n; ++i) 
    for (int j=0; j<n; ++j) 
            /*
            实际中为防止溢出，往往需要选判断 dist[i][k]和dist[k][j]
            都不是Inf ，只要一个是Inf，那么就肯定不必更新。 
            */
      if (dist[i][k] + dist[k][j] < dist[i][j] ){
        dist[i][j] = dist[i][k] + dist[k][j];
        //记录path
        path[i][j]=k;
      }
```

关于动态规划的思想详细解析

- 时间复杂度

  一目了然

### 迷宫算法

迷宫算法可以使用Dij算法，但一般的迷宫问题都类似于"无权图"问题，因此算法流程可以更简洁。与任意节点相邻的节点最多只有四个。这样连遍历的过程都省略了。迷宫算法也能用BFS算法模拟，使用堆栈记录路径。


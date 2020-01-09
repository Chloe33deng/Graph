//
//  Hospital.h
//  医院选址问题
//
//  Created by Noah on 2020/1/10.
//  Copyright © 2020 Noah. All rights reserved.
//

#ifndef Hospital_h
#define Hospital_h

const int MaxValue = 100; //定义const常量 100
const int N = 5; //假设图中有5个顶点
class Hospital
{
public:
Hospital(char v[N],int e[N][N], int n); //构造函数
~Hospital( ); //析构函数
void Floyd(int dist[N][N]); //求任意两个顶点之间的最短路径
int Center( ); //求图的中心点，返回中心点的下标
private:
char vertex[N] ; //一维数组存放顶点信息
int edge[N][N]; //二维数组存放邻接关系
int vertexNum; //顶点个数
};
#endif /* Hospital_h */

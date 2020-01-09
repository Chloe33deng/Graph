//
//  Hospital.cpp
//  医院选址问题
//
//  Created by Noah on 2020/1/10.
//  Copyright © 2020 Noah. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Hospital.h"

Hospital :: Hospital(char v[N], int e[N][N], int n)
{
for (int i = 0; i < n; i++) //初始化顶点信息
vertex[i] = v[i];
for(int i = 0; i < n; i++) //初始化邻接矩阵
for (int j = 0; j < n; j++)
edge[i][j] = e[i][j] ;
vertexNum = n;
}

Hospital :: ~Hospital( )
{

}

void Hospital :: Floyd(int dist[N][N])
{
int i, j, k;
for (i = 0; i < vertexNum; i++) //初始化结果矩阵dist
for (j = 0; j < vertexNum; j++)
dist[i][j] = edge[i][j];
for (k = 0; k < vertexNum; k++) //进行N次迭代
for (i = 0; i < vertexNum; i++) //顶点i和j之间是否经过顶点k
for (j = 0; j < vertexNum; j++)
if (dist[i][k] + dist[k][j] < dist[i][j])
dist[i][j] = dist[i][k] + dist[k][j];
}

int Hospital :: Center( )
{
int wayCost, minCost = MaxValue;
int i, k, index, dist[N][N]; //矩阵dist存储顶点之间的最短路径长度
Floyd(dist);
for (k = 0; k < vertexNum; k++) //依次求每个顶点的往返代价
{
wayCost = 0; //往返代价初始化为0
for (i = 0; i < vertexNum; i++) //顶点i到其他顶点的路径长度之和
wayCost = wayCost + dist[i][k];
for (i = 0; i < vertexNum; i++) //其他顶点到顶点i的路径长度之和
wayCost = wayCost + dist[k][i];
if (wayCost < minCost) {
minCost = wayCost;
index = k; //顶点k为当前的中心点
}
}
return index; //返回中心点的下标
}

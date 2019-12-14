
#include<iostream>
using namespace std;
#include"MGraph.h"//引入MGraph.h的声明
extern int visited[MaxSize];

template <class DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e)
{
	int i, j, k;
	vertexNum = n;
	arcNum = e;
	for (i = 0;i < vertexNum;i++)//储存图的顶点信息 

		vertex[i] = a[i];
	for (i = 0;i < vertexNum;i++)
		for (j = 0;j < vertexNum;j++)//初始化邻接矩阵
			arc[i][j] = 0;
	for (k = 0;k < arcNum;k++)
	{
		cout << "请输入边的两个顶点的序号:";
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = 1;

	}
}
template<class DataType>
void MGraph<DataType>::DFSTraverse(int v)//深度遍历
{
	cout << vertex[v];//v是下标 

	visited[v] = 1; //先定义

	for (int j = 0;j < vertexNum;j++)
		if (arc[v][j] = 1 && visited[j] == 0)//前者说明两个点是邻接点 后边说明没有被访问过
			DFSTraverse(j);
}

template<class DataType>
void MGraph<DataType>::BFSTraverse(int v)//广度优先
{
	int Q[MaxSize];//假设队列采用顺序存储并不会发生溢出
	int front = -1;
	int rear = -1;//初始化队列
	cout << vertex[v];
	visited[v] = 1;
	Q[++rear] = v; //被访问顶点入队
	while (front != rear)//当队列非空
	{
		v = Q[++front];//将对头元素出队并送入v中
		for (int j = 0;j < vertexNum;j++)
			if (arc[v][j] = 1 && visited[j] == 0)

			{
				cout << vertex[j];
				visited[j] = 1;
				Q[++rear] = j;
			}
	}
}

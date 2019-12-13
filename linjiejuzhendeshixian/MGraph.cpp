#include <iostream>
using namespace std;
#include"MGraph.h"

template<class DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e)
{
	int i, j, k;
	vertexNum = n, arcNum = e;
	for (i = 0; i < vertexNum; i++)
		vertex[i] = a[i];
	for (i = 0; i < vertexNum; i++)
		for (j = 0; j < vertexNum; j++)
			arc[i][j] = 0;
	for (k = 0; k < arcNum; k++)
	{
		cout << "请输入边的两个顶点的序号：";
		cin >> i >> j;
		arc[i][j] = 1; arc[j][i] = 1;
	}
}
template<class DataType>
void MGraph<DataType>::DFSTraverse(int v)
{
	cout << vertex[v]; 
	visited[v] = 1;
	for (int j = 0; j < vertexNum; j++)
		if (arc[v][j] == 1 && visited[j] == 0)
			DFSTraverse(j);
}

template<class DataType>
void MGraph<DataType>::BFSTraverse(int v)
{
	int Q[MaxSize];
	int w, j;
	int front = -1, rear = -1;
	cout << vertex[v]; 
	visited[v] = 1; Q[++rear] = v;
	while (front != rear)
	{
		w = Q[++front];
		for(j=0;j<vertexNum;j++)
			if (arc[w][j] == 1 && visited[j] == 0)
			{
				cout << vertex[j];
				visited[j] = 1; 
				Q[++rear]=j;
			}
	}
}
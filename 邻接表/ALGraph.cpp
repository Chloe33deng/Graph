#include<iostream>
using namespace std;
#include"ALGraph.h"
extern int visited[MaxSize];
extern int adjvex;
template<class DataType>
ALGraph<DataType>::ALGraph(DataType a[], int n, int e)
{
	ArcNode* s;
	int i, j, k;
	vertexNum = n;arcNum = e;
	for (i = 0;i < vertexNum;i++)
	{
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;
	}
	for (k = 0;k < arcNum;k++)
	{
		cout << "������ߵ������������:";
		cin >> i >> j;
		s = new ArcNode;s -> adjvex = j;
		s -> next = adjlist[i].firstedge;
		adjlist[i].firstedge = s;
	}
}
template<class DataType>
ALGraph<DataType>::~ALGraph()
{
	ArcNode* p = NULL;
	for (int i = 0;i < vertexNum;i++)
	{
		p = adjlist[i].firstedge;
		while (p != NULL)
		{
			adjlist[i].firstedge = p -> next;
			delete p;
			p = adjlist[i].firstedge;
		}
	}
}
template<class DataType>
void ALGraph<DataType>::DFSTraverse(int v)
{
	ArcNode* p = NULL;int j;
	cout << adjlist[v].vertex;
	visited[v] = 1;
	p = adjlist[v].firstedge;
	while (p != NULL)
	{
		j = p ->adjvex;
		if (visited[j] == 0)DFSTraverse(j);
		p = p -> next;
	}
}
template<class DataType>
void ALGraph<DataType>::BFSTraverse(int v)
{
	int Q[MaxSize];
	int front = -1, rear = -1;
	ArcNode* p = NULL;
	cout << adjlist[v].vertex;
	visited[v] = 1;
	Q[++rear] = v;
	while (front != rear)
	{
		v = Q[++front];
		p = adjlist[v].firstedge;
		while (p != NULL)
		{
			int j = p ->adjvex;
			if (visited[j] == 0) {
				cout << adjlist[j].vertex;
				visited[j] = 1;
				Q[++rear] = j;
			}
			p = p -> next;
		}
	}
}

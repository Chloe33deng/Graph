// ALGraph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include"ALGraph.h"


template<class DataType>
ALGraph<DataType>::ALGraph(DataType a[], int n, int e)
{
	ArcNode *s;
	int i, j, k;
	vertexNum = n; arcNum = e;
	for (i = 0; i < vertexNum; i++)
	{
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;
	}
	for (k = 0; k < arcNum; k++)
	{
		cout << "请输入边的两个顶点的序号：";
		cin >> i >> j;
		s = new ArcNode; s->adjvex = j;
		s->next = adjlist[i].firstedge;
		adjlist[i].firstedge = s;
	}
}

template<class DataType>
ALGraph<DataType>::~ALGraph()
{
	ArcNode *p;
	for (int i = 0; i < vertexNum; i++)
	{
		p = adjlist[i].firstedge;
		while (p != NULL)
		{
			adjlist[i].firstedge = p->next;
			delete p;
			p = adjlist[i].firstedge;
		}
	}
}
template<class DataType>
void ALGraph<DataType>::DFSTraverse(int v)
{
	ArcNode *p; int j;
	cout << adjlist[v].vertex; visited[v] = 1;
	p = adjlist[v].firstedge;
	while (p != NULL)
	{
		j = p->adjvex;
		if (visited[j] == 0)DFSTraverse(j);
		p = p->next;
	}
}

template<class DataType>
void ALGraph<DataType>::BFSTraverse(int v)
{
	int Q[MaxSize];
	int front = -1, rear = -1;
	ArcNode *p;
	cout << adjlist[v].vertex; visited[v] = 1; Q[++rear] = v;
	while (front != rear)
	{
		v = Q[++front];
		p = adjlist[v].firstedge;
		while (p != NULL)
		{
			int j = p->adjvex;
			if (visited[j] == 0)
			{
				cout << adjlist[j].vertex; visited[j] = 1; Q[++rear] = j;
			}
			p = p->next;
		}
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#// MGraph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

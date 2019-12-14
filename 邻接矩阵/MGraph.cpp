
#include<iostream>
using namespace std;
#include"MGraph.h"//����MGraph.h������
extern int visited[MaxSize];

template <class DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e)
{
	int i, j, k;
	vertexNum = n;
	arcNum = e;
	for (i = 0;i < vertexNum;i++)//����ͼ�Ķ�����Ϣ 

		vertex[i] = a[i];
	for (i = 0;i < vertexNum;i++)
		for (j = 0;j < vertexNum;j++)//��ʼ���ڽӾ���
			arc[i][j] = 0;
	for (k = 0;k < arcNum;k++)
	{
		cout << "������ߵ�������������:";
		cin >> i >> j;
		arc[i][j] = 1;
		arc[j][i] = 1;

	}
}
template<class DataType>
void MGraph<DataType>::DFSTraverse(int v)//��ȱ���
{
	cout << vertex[v];//v���±� 

	visited[v] = 1; //�ȶ���

	for (int j = 0;j < vertexNum;j++)
		if (arc[v][j] = 1 && visited[j] == 0)//ǰ��˵�����������ڽӵ� ���˵��û�б����ʹ�
			DFSTraverse(j);
}

template<class DataType>
void MGraph<DataType>::BFSTraverse(int v)//�������
{
	int Q[MaxSize];//������в���˳��洢�����ᷢ�����
	int front = -1;
	int rear = -1;//��ʼ������
	cout << vertex[v];
	visited[v] = 1;
	Q[++rear] = v; //�����ʶ������
	while (front != rear)//�����зǿ�
	{
		v = Q[++front];//����ͷԪ�س��Ӳ�����v��
		for (int j = 0;j < vertexNum;j++)
			if (arc[v][j] = 1 && visited[j] == 0)

			{
				cout << vertex[j];
				visited[j] = 1;
				Q[++rear] = j;
			}
	}
}

#pragma once
#ifndef MGraph_H
#define MGraph_H

const int MaxSize = 100;


template<class DataType>
class MGraph
{
public:
	MGraph(DataType a[], int n, int e);
	~MGraph() {}
	void DFSTraverse(int v);
	void BFSTraverse(int v);
private:
	DataType vertex[MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum, arcNum;
	int visited[MaxSize];
};
#endif // !MGraph_H

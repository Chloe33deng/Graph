#pragma once
# ifndef ALGraph_H
# define ALGraph_H
const int MaxSize = 10;

struct ArcNode
{
	int adjvex;
	ArcNode* next;
};
template<class DateType>
struct VertexNode
{
	DateType vertex;
	ArcNode* firstedge;
};
template<class DataType>
class ALGraph
{
public:
	ALGraph(DataType a[], int n, int e);
	~ALGraph();
	void DFSTraverse(int v);
	void BFSTraverse(int v);
private:
	VertexNode<DataType>adjlist[MaxSize];
	int vertexNum, arcNum;
};
#endif // !ALGraph_H


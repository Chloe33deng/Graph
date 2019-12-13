#ifndef ALGraph_H
#define ALGraph_H
const int MaxSize = 100;

struct ArcNode
{
	int adjvex;
	ArcNode *next;
};
template<class DataType>
struct VertexNode
{
	DataType vertex;
	ArcNode *firstedge;
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
	int visited[MaxSize];
};
#endif // !ALGraph_H

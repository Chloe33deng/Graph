
#ifndef MGraph_H//避免包含MGraph.h的头文件
#define MGraph_H
const int MaxSize = 10;//图中最多的顶点
template<class DataType>

class MGraph
{
public:
	MGraph(DataType a[], int n, int e);//建立n个顶点 e条变
	~MGraph() {	}
	void DFSTraverse(int v);//深度遍历 
	void BFSTraverse(int v);//广度遍历，v是指顶点的下标
private:
	DataType vertex[MaxSize];//顶点数组 
	int arc[MaxSize][MaxSize];//存放图中边的数组
	int vertexNum, arcNum;
};
#endif;



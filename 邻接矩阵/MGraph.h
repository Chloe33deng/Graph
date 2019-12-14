
#ifndef MGraph_H//�������MGraph.h��ͷ�ļ�
#define MGraph_H
const int MaxSize = 10;//ͼ�����Ķ���
template<class DataType>

class MGraph
{
public:
	MGraph(DataType a[], int n, int e);//����n������ e����
	~MGraph() {	}
	void DFSTraverse(int v);//��ȱ��� 
	void BFSTraverse(int v);//��ȱ�����v��ָ������±�
private:
	DataType vertex[MaxSize];//�������� 
	int arc[MaxSize][MaxSize];//���ͼ�бߵ�����
	int vertexNum, arcNum;
};
#endif;



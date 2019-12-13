#include<iostream>
using namespace std;
#include"MGraph.cpp"
int visited[MaxSize] = { 0 };

int main()
{
	char ch[6] = { 'A','B','C','D','E'};
	int i;
	MGraph<char>MG(ch, 5, 6);
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout << "深度优先遍历序列是：";
	MG.DFSTraverse(0);
	cout << endl;
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout << "广度优先遍历序列是：";
	MG.BFSTraverse(0);
	cout << endl;
	return 0;
}
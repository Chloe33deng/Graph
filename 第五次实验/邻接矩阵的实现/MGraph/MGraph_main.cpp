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
	cout << "������ȱ��������ǣ�";
	MG.DFSTraverse(0);
	cout << endl;
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout << "������ȱ��������ǣ�";
	MG.BFSTraverse(0);
	cout << endl;
	return 0;
}
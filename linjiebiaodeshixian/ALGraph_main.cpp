#include <iostream>
using namespace std;
#include "ALGraph.cpp"
int visited[MaxSize] = { 0 };

int main()
{
	char ch[] = { 'A','B','C','D','E' };
	int i;
	ALGraph<char> ALG(ch, 5, 6);
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout << "������ȱ���������:";
	ALG.DFSTraverse(0);
	cout << endl;
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout << "������ȱ��������ǣ�";
	ALG.BFSTraverse(0);
	cout << endl;
	getchar();
	getchar();
	system("pause");
	return 0;
}
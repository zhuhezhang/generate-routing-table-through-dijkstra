//�ļ�������ӱߡ����㺯�� 
#include "GenerateRoutingTableDijkstra.h"

//��ӱ�
void Graph::Add_edge()
{
	string from, to;
	int f, t, value;
	cout << "��������Ҫ��ӵıߣ���ʽ����� �յ� Ȩֵ��";
	cin >> from >> to >> value;
	for (f = 0; f < this->vernum; f++)    //�ҵ�����Ӧ���������� 
	{
		if (from.compare(node[f].router) == 0)
		    break;
    }
    for (t = 0; t < this->vernum; t++)    //�ҵ��յ��Ӧ���������� 
	{
		if (to.compare(node[t].router) == 0)
			break;
	}
	adjmatrix[f][t] = value;              //���ڽӾ����Ӧ�ϵĵ㸳ֵ
    adjmatrix[t][f] = value;
    this->edge++;
}

//��Ӷ���
void Graph::Add_vertex()
{
    int i, j, e, value;
    string from, to;
	cout << "����������ӵ�·�������ڵı�����";
	cin >> e;
	cout << "����������ÿ���߼���Ȩֵ����ʽ����� �յ� Ȩֵ��" << endl;
	for(i = 0; i < e; i++)
	{
		cin >> from >> to >> value;
		for (j = 0; j < this->vernum; j++)//�ҵ��յ��Ӧ����������
	    {
		    if (to.compare(node[j].router) == 0)
		    	break;
	    }
		adjmatrix[this->vernum][j] = value;
		adjmatrix[j][this->vernum] = value;
		node[this->vernum].router = from;
	}
	this->vernum++;
	this->edge = this->edge + e;
}

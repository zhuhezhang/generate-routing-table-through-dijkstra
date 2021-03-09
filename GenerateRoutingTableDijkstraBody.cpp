//�ļ������㷨���庯�������õϽ�˹���㷨�������·�� 

#include "GenerateRoutingTableDijkstra.h"
//�㷨����
void Graph::Dijkstra()
{
    int f, i, j, k;
    string from;
	cout<<"���������������·������";
	cin >> from;
	cout << endl;
	for (f = 0; f < this->vernum; f++)
	{
		if (from.compare(node[f].router) == 0)
			break;
	}
    for (i = 0; i < this->vernum; i++)//��ʼ��node����
	{
        node[i].path = from + "-->" + node[i].router;
        node[i].next_router = node[i].router;
        node[i].des_router = node[i].router;
        node[i].value = adjmatrix[f][i];
        node[i].visit = false;
    }
    node[f].value = 0;                //�������ĵ�����·��Ϊ0
    node[f].visit = true;

    for (i = 1; i < this->vernum; i++)//����ʣ��Ķ�������·��
	{
        int temp = 0;                 //temp���ڱ��浱ǰnode��������С���Ǹ��±�
        int min = MAX_VALUE;          //min��¼�ĵ�ǰ����Сֵ
        for (j = 0; j < this->vernum; j++)
		{
            if (!node[j].visit && node[j].value < min)
			{
                min = node[j].value;
                temp = j;
            }
        }
        node[temp].visit = true;      //��temp��Ӧ�Ķ�����뵽�Ѿ��ҵ������·���ļ�����
        for (k = 0; k < this->vernum; k++)
		{
            if (!node[k].visit && adjmatrix[temp][k] != MAX_VALUE && (node[temp].value + adjmatrix[temp][k]) < node[k].value)
			{//����µõ��ı߿���Ӱ������Ϊ���ʵĶ��㣬������������·���ͳ���
                node[k].path = node[temp].path + "-->" + node[k].router;
                node[k].des_router = node[k].router;
                node[k].next_router = node[temp].next_router + node[k].router;
                node[k].value = node[temp].value + adjmatrix[temp][k];
            }
        }
    }
    Display_table(from);
}

//���ļ���������ͼ����
#include "GenerateRoutingTableDijkstra.h"

//����ͼ
void Graph::Create_graph()
{
	ifstream in("GenerateRoutingTableDijkstra.txt");
	int vernum,edge;
    in >> vernum >> edge;                     //�ļ�¼����Ϣ
    this->vernum = vernum;                    //��ʼ���������ͱ���
    this->edge = edge;
    node = new Node[MAX_VERNUM];              //����������Ϣ�����й���MAX_VERNUM����
    adjmatrix = new int*[MAX_VERNUM];         //����һά����ΪMAX_VERNUM
    for (int i = 0; i < MAX_VERNUM; i++)
	{
        adjmatrix[i] = new int[MAX_VERNUM];   //�����ά����ҲΪMAX_VERNUM
        for (int k = 0; k < MAX_VERNUM; k++)
		{
            adjmatrix[i][k] = MAX_VALUE;      //�ڽӾ����ʼ��Ϊ�����
        }
    }

	int start, end, value, count = 0;
    while (count < this->edge)
	{
        in >> start >> end >> value;          //�ļ�¼����Ϣ 
        adjmatrix[start - 1][end - 1] = value;//���ڽӾ����Ӧ�ϵĵ㸳ֵ
        adjmatrix[end - 1][start - 1] = value;
        count++;
    }

    for (int i = 0; i < this->vernum; i++)    //��ʼ��node�����·�������router 
	{
        node[i].router = "r" + to_string(i + 1);
    }
    in.close();
}

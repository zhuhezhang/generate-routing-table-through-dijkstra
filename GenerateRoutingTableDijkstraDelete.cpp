//���ļ�����ɾ���ߡ����㺯�� 
#include "GenerateRoutingTableDijkstra.h"

//ɾ����
void Graph::Del_edge()
{
	string from, to;
	int r, i, j;
	cout << "��������Ҫɾ���ıߣ���ʽ����� �յ㣩";
	cin >> from >> to;
	for (i = 0; i < this->vernum; i++)
	{
		if (from.compare(node[i].router) == 0)
			break;
	}
	for (j = 0; j < this->vernum; j++)
	{
		if (to.compare(node[j].router) == 0)
			break;
	}
	adjmatrix[i][j] = MAX_VALUE;        //���ڽӾ����Ӧ�ϵĵ㸳ֵ
    adjmatrix[j][i] = MAX_VALUE;
    this->edge--;
}

//ɾ������
void Graph::Del_vertex()
{
	string r1;
	int r2, i, j, count = 0;
	cout << "��������Ҫɾ����·������";
	cin >> r1;
	for (r2 = 0; r2 < this->vernum; r2++)
	{
		if (r1.compare(node[r2].router) == 0)
			break;
	}
	for (i = 0; i < this->vernum; i++)  //ͳ����ɾ���Ķ�����صı��� 
	{
		if(adjmatrix[r2][i] != MAX_VALUE)
		    count++;
	}

    for(i = 0;i < this->vernum; i++)    //�����ڽӾ���
    {
        for(j = 0;j < this->vernum; j++)//���ڽӾ������ڽ���
        {
            if(i > r2 && j > r2)        //�������½ǲ���
                adjmatrix[i-1][j-1] = adjmatrix[i][j];
            else if(i > r2)             //�������Ͻǲ���
                adjmatrix[i-1][j] = adjmatrix[i][j];
            else if(j > r2)             //�������½ǲ���
                adjmatrix[i][j-1] = adjmatrix[i][j];
        }
    }
    for(i = 0;i < this->vernum; i++)
    	adjmatrix[this->vernum][i] = MAX_VALUE;
    for(i = 0;i < this->vernum; i++)
        adjmatrix[i][this->vernum] = MAX_VALUE;
    for(i = r2; i < this->vernum-1; i++)//������������ֵ
        node[i] = node[i+1];
    this->vernum--;
    this->edge = this->edge - count;
}

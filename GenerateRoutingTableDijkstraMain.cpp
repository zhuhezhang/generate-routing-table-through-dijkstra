//�˳���������ָ��·����·�ɱ����ļ�Ϊ������
#include "GenerateRoutingTableDijkstra.h"

//������
int main(void)
{
	Graph graph;
    graph.Create_graph();
    first:
    switch(graph.Menu())
    {
    	case 1:
    	{
    		system("cls");  //�����Ļ
			graph.Dijkstra();
			system("pause");//����������� 
			goto first;
		}
		case 2:
    	{
    		system("cls");
    		graph.Del_edge();
			system("pause");
			goto first;
		}
		case 3:
    	{
    		system("cls");
    		graph.Add_edge();
			system("pause");
			goto first;
		}
		case 4:
    	{
    		system("cls");
    		graph.Del_vertex();
			system("pause");
			goto first;
		}
		case 5:
    	{
    		system("cls");
    		graph.Add_vertex();
			system("pause");
			goto first;
		}
	}
    return 0;
}

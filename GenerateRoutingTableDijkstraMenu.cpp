//�ļ���������˵��������������Ͷ�������ֵ�Ƿ�Ϸ����� 
#include "GenerateRoutingTableDijkstra.h"

//����˵� 
int Graph::Menu()
{
	int i;
	do{
		system("cls");
		cout<<"**********·�ɱ�����ϵͳ�˵�********"<<endl<<endl;
		cout<<"            1.���·�ɱ�            "<<endl;
		cout<<"            2.ɾ����                "<<endl;
		cout<<"            3.��ӱ�                "<<endl;
		cout<<"            4.ɾ������              "<<endl;
		cout<<"            5.��Ӷ���              "<<endl;
		cout<<"            6.�˳�����              "<<endl;	
		cout<<"            ����������ѡ��";
		cin>>i;
		}while(i<1||i>6);
	return i;
}

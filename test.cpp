#include "list.h"
#include "iostream"
using namespace std;
int main()
{
	Node node1(2);
	Node node2(3);
	Node node3(4);
	Node node4(5);
	Node node5(6);
	Node node6(7);
	Node node7(8);
	List my_lis;
	my_lis.inser_head(node1);   //ͷ�ڵ����
	my_lis.inser_head(node2);
	my_lis.inser_tail(node3);   //β�ڵ����
	my_lis.inser_i(node4, 2);
	my_lis.inser_i(node5, 0);   //����ڵ����
	my_lis.inser_head(node6);
	my_lis.inser_i(node7, 6);
	my_lis.traverse();  //�������ԣ���ȷ���ӦΪ��7 6 3 2 5 4 8

	Node i_node;
	my_lis.get_i_node(3, &i_node);     //��ȡ�±�Ϊi��Ԫ��
	cout <<i_node.data << endl;
	cout<<my_lis.get_node_i(node3)<<endl;   //��ȡnode3���ڵ��±�

	Node pre_node;
	my_lis.get_pre_node(node3,&pre_node);   //��ȡnode3��ǰһ��Ԫ��
	cout << pre_node.data << endl;

	Node next_node;
	my_lis.get_next_node(node3, &next_node);  //��ȡnode3�ĺ�һ��Ԫ��
	cout <<next_node.data << endl;

	my_lis.delete_head();    //ɾ��ͷ�ڵ�
	my_lis.delete_tail();    //ɾ��β�ڵ�
	my_lis.delete_i(3);      //ɾ���±�Ϊ3�Ľڵ�
	cout << my_lis.length() << endl;   //��ȡ����
	my_lis.traverse();
	my_lis.clean();
	my_lis.traverse();

	return 0;
}
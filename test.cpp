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
	my_lis.inser_head(node1);   //头节点插入
	my_lis.inser_head(node2);
	my_lis.inser_tail(node3);   //尾节点插入
	my_lis.inser_i(node4, 2);
	my_lis.inser_i(node5, 0);   //任意节点插入
	my_lis.inser_head(node6);
	my_lis.inser_i(node7, 6);
	my_lis.traverse();  //遍历测试，正确输出应为：7 6 3 2 5 4 8

	Node i_node;
	my_lis.get_i_node(3, &i_node);     //获取下标为i的元素
	cout <<i_node.data << endl;
	cout<<my_lis.get_node_i(node3)<<endl;   //获取node3所在的下标

	Node pre_node;
	my_lis.get_pre_node(node3,&pre_node);   //获取node3的前一个元素
	cout << pre_node.data << endl;

	Node next_node;
	my_lis.get_next_node(node3, &next_node);  //获取node3的后一个元素
	cout <<next_node.data << endl;

	my_lis.delete_head();    //删除头节点
	my_lis.delete_tail();    //删除尾节点
	my_lis.delete_i(3);      //删除下标为3的节点
	cout << my_lis.length() << endl;   //获取长度
	my_lis.traverse();
	my_lis.clean();
	my_lis.traverse();

	return 0;
}
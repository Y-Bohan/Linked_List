#ifndef LIST_H
#define LIST_H

#include "iostream"
using namespace std;
class Node
{
public:
	Node(int x) { data = x; }
	Node() {}
	int data;
	Node* next;
	int i_len;
};

class List
{
public:
	List();     //���캯������ʼ������
	~List();    //�����������ͷŶ����ڴ�ռ�
	void clean();    //���
	bool empty();    //  �п�
	int length();    //  ��ȡ������
	bool inser_head(Node node);          //����ͷ�ڵ�
	bool inser_tail(Node node);          //����β�ڵ�
	bool inser_i(Node node, int i);      //��������ڵ㣨���ܲ嵽��������ռ��⣩
	bool delete_head();            //ɾ��ͷ�ڵ�
	bool delete_tail();            //ɾ��β�ڵ�
	bool delete_i(int i);           //ɾ������ڵ�
	bool get_i_node(int i, Node* i_node);                //��ȡ�±�Ϊi�Ľڵ�
	int get_node_i(Node node);                //���ҵ�һ������nodeʱ���±�
	bool get_pre_node(Node node, Node* pre_node);             //��ȡnode��ǰһ���ڵ�
	bool get_next_node(Node node, Node* next_node);                 //��ȡnode�ĺ�һ���ڵ�
	bool traverse();           //��������
private:
	Node* p;       //����ͷ
	int i_len;     //������
};

#endif
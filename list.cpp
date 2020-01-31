#include "list.h"
#include "iostream"
using namespace std;
List::List()
{
	p = new Node;
	p->data = 0;
	p->next = NULL;
	i_len =0;
}

List::~List()
{
	clean();
	delete p;
	p = NULL;
	cout << "**********~List()" << endl;
}

void List::clean()
{
	Node *current = p->next;
	Node*  temp;
	while (current!= NULL)
	{
		temp = current->next;
		delete current;
		current = temp;
	}
	p->next = NULL;
	i_len = 0;
}

bool List::empty()
{
	return i_len == 0 ? true : false;
}

int List::length()
{
	return i_len;
}

bool List::inser_head(Node node)
{
	cout << "insert head_node" << endl;
	Node* new_node = new Node;   //因为是新插入的节点，所以必须在堆中申请内存，否则函数执行完成后会自动释放内存
	new_node->data = node.data;
	new_node->next = p->next;
	p->next = new_node;
	i_len++;
	return true;
}

bool List::inser_tail(Node node)
{
	cout << "insert tail_node" << endl;
	Node* current =p;
	Node* new_node = new Node;
	while (current->next != NULL)
	{
		current = current->next;
	}
	new_node->data = node.data;
	new_node->next = current->next;
	current->next = new_node;
	i_len++;
	return true;
}

bool List::inser_i(Node node, int i)
{
	if (i<0 || i>i_len)
	{
		cout << "can't insert" << endl;
		return false;
	}
	if (i == 0 || i == i_len)
		{
			i == 0 ? inser_head(node) : inser_tail(node);
			return true;
		}
	Node* current = p;
	while (i > 0)
	{
		current = current->next;
		i--;
	}
	Node* new_node = new Node;
	new_node->data = node.data;
	new_node->next = current->next;
	current->next = new_node;
	i_len++;
	return true;
}

bool List::delete_head()
{
	if (p->next == NULL)
	{
		cout << "error,can not delete head_node" << endl;
		return false;
	}
	cout << "deleye head_node" << endl;
	Node* temp = p->next;
	temp = temp->next;
	p->next = temp;
	i_len--;
	return true;
}

bool List::delete_tail()
{
	if (p->next == NULL)
	{
		cout << "error,can not delete tail_node" << endl;
		return false;
	}
	cout << "delete tail_node" << endl;
	Node* current = p;
	Node* temp=NULL;
	while (current->next != NULL)
	{
	    temp = current;
		current = current->next;
	}
	delete current;
	current = NULL;
	temp->next = NULL;
	i_len--;
	return true;
}

bool List::delete_i(int i)
{
	if (i<0 || i>i_len)
	{
		cout << "can not delete" << endl;
		return false;
	}
	cout << "delete node" << endl;
	if (i == 0 || i == i_len)
	{
		i == 0 ? delete_head() : delete_tail();
		return true;
	}
	Node *current = p;
	while (i > 0)
	{
		current = current->next;
		i--;
	}
	Node *temp = current->next;
	current->next = temp->next;
	delete temp;
	temp = NULL;
	i_len--;
	return true;
}

bool List::get_i_node(int i,Node* i_node)
{
	if (i<0 || i>i_len)
	{
		cout << "can not get node " << i << endl;
		return false;
	}
	cout << "get node " << i << endl;
	Node* current = p;
	while (i >= 0)
	{
		current = current->next;
		i--;
	}
	i_node->data = current->data;
	i_node->next = current->next;
	return true;
}

int List::get_node_i(Node node)
{
	Node* current = p->next;
	int i = 0;
	while (current != NULL)
	{
		if (current->data == node.data)
		{
			return i;
		}
		current = current->next;
		i++;
	}
	cout << "can not find " << endl;
	return -1;
}

bool List::get_pre_node(Node node, Node* pre_node)
{
	int i=get_node_i(node);
	if (i <= 0)
	{
		cout << "no pre_node" << endl;
		return false;
	}
	get_i_node(i-1,pre_node);
	return true;
}

bool List::get_next_node(Node node, Node* next_node)
{
	int i = get_node_i(node);
	if (i < 0||i==i_len-1)
	{
		cout << "no next_node" << endl;
		return false;
	}
	get_i_node(i+1, next_node);
	return true;
}

bool List::traverse()
{
	if (p->next == NULL)
	{
		cout << "empty,can not traverse" << endl;
		return false;
	}
	Node* current = p->next;
	while (current != NULL)
	{
		cout << current->data<<" ";
		current = current->next;
	}
	cout << endl;
	return true;
}
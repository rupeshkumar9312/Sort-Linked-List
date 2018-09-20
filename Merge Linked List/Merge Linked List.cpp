#include"stdafx.h"
#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
	int data;
	Node *next;

};

class LinkedList
{
private:
	Node * head;
	Node* sortHead;
public:
	LinkedList() {
		head = NULL;
	}

	~LinkedList()
	{
		//cleanUp();
	}
	void merge(LinkedList list, LinkedList list1);
	void view();
	void push(int value);
	void traverseList();
	void remove(int value);
	void fun();
	void sort(LinkedList list, LinkedList new_list);
	Node* fun1(LinkedList list);
	void fun2(LinkedList list);
	void sortList(LinkedList list,Node *newnode);
	void insertionSort(LinkedList list,LinkedList list1);
};

void LinkedList::fun2(LinkedList list)
{
	Node* min = list.head;
	Node * current = list.head;
	while (current != NULL)
	{
		min = fun1(list);
		
		current = current->next;
	}
	cout << "MINIMUM -->" << min->data;
	
}

Node* LinkedList ::fun1(LinkedList list)
{
	
	Node* current = list.head;
	Node *min = current;
	while (current != NULL)
	{
		if (current->data < min->data)
		{
			min = current;

		//	cout << "In fun1";
			
		}
		current = current->next;
	}
	return min;
}

void LinkedList::sort(LinkedList list, LinkedList new_list)
{
	//cout << "HELL)";
	Node *current = list.head;
	Node *current1 = current;
	Node* min = current;
	Node * temp = min;
	Node *pre = current;
	bool b = false, c = false;
	while (current1 != NULL)
	{
		current = current1;
		
		while (current != NULL)
		{
			if (current->data < min->data && current->data != 0)
			{
				//if(current->data != min->data)
				
				min = current;
				temp = current;
				b = true;
			}
			else
			{
				pre = current;
				current = current->next;
			}

		}

		cout << "MIN " << min->data << endl;
		temp->data = 0;
		current1 = current1->next;
	}
		//cout << min->data << "-->";
	/*	if (new_list.head == NULL)
		{

			new_list.head = min;
			new_list.head->next = NULL;
		}
		else
		{
			new_list.head->next = min;
			new_list.head = min;
		}*/

	//}
	
}
void LinkedList::merge(LinkedList list, LinkedList list1)
{
	Node *current = list.head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = list1.head;
}

void LinkedList::push(int value)
{
	//Node * current = head;
	Node *new_node = new Node;
	new_node->data = value;
	new_node->next = NULL;
	if (head == NULL)
	{
		//new_node = head;
		head = new_node;
		return;
	}
	new_node->next = head;
	head = new_node;


}

void LinkedList::view()
{
	if (head == NULL)
	{
		cout << "No item in List" << endl;
		return;
	}
	if (head->next == NULL)
	{
		cout << head->data << "-->NULL" << endl;
		return;
	}
	Node *current = head;
	while (current != NULL)
	{
		cout << current->data << "-->";
		current = current->next;
	}
	cout << "NULL";
}
void LinkedList::remove(int value)
{
	int c = 0;
	Node* current = head;
	Node* previous = NULL;
	int count = 0;
	while (current != NULL)
	{
		//	c++;
		//current = current->next;
		if (current != NULL && current->data == value)
		{
			count++;
		}
		if (count > 1 && current->data == value)
		{
			c++;
			current = current->next;
			//previous->next = current->next->next;
			previous->next = current;

			//current = current->next;
			continue;
		}
		previous = current;
		current = current->next;
		//cout << "count " << count << endl;
	}
	//cout << "Loop " << c << endl;
}
void LinkedList::fun()
{
	Node *current = head;
	while (current != NULL)
	{
		remove(current->data);
		current = current->next;
	}


	//	Node* node = new Node;
	//node = head;
}

void LinkedList::traverseList()
{
	Node* current = head;
	while (current != NULL)
	{
		cout << current->data << "-->";
		current = current->next;
	}
	cout << "NULL";
	return;
}
int main()
{
	LinkedList list;
	//int choice, value, addedValue;
	Node *head = NULL;

	list.push(25);
	list.push(20);
	list.push(30);
	LinkedList list1;
	list1.push(40);
	list1.push(50);
	list1.push(20);
	list1.push(50);
	list1.push(60);

	list1.push(60);
	
	list.merge(list, list1);
	cout << "List after merge " << endl;
	list.view();
	cout << endl;
	cout << "List after Removing Duplicates" << endl;
	list.fun();
	list.view();
	cout << endl;

	LinkedList list2;
	cout << "List after sorting" << endl;
	//.list.sort(list, list2);
	list.insertionSort(list, list2);
	//list.view();
	//list.fun2(list);
	list.view();
	return 0;
}
void LinkedList::insertionSort(LinkedList list,LinkedList list1)
{
	list1.head = NULL;
	Node* current = list.head;
	while (current != NULL)
	{
		Node* next = current->next;
		
		sortList(list,current);

		current = next;
	}
	
	head = sortHead;
}

void LinkedList::sortList(LinkedList list,Node* newnode)
{
	
	if (sortHead == NULL || sortHead->data >= newnode->data)
	{
		newnode->next = sortHead;
		sortHead = newnode;
	}
	else
	{
		Node* current = sortHead;
		while (current->next != NULL && current->next->data < newnode->data)
		{
			current = current->next;
		}
		newnode->next = current->next;
		current->next = newnode;
	}
}

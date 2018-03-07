#include <iostream>
using namespace std;

/*
*反转单向链表,和双向链表
*
*/

struct Node{
	int val;
	Node(int a) { val = a; next = NULL; };
	Node* next;
};

void printList(Node* node)
{
	if(node==NULL){
		std::cout<<std::endl;
		return;
	}

	std::cout<<node->val<<" ";
	printList(node->next);
}

void reverse_list(Node* node){

	Node* a=NULL;
	Node* target=node;
	while(target!=NULL){
		Node* b=target->next;
		target->next=a;
		a=target;
		target=b;
	}	
}

int main()
{
	Node* start = new Node(0);
	Node* pN = start;
	pN->next=new Node(1);
	pN=pN->next;
	pN->next=new Node(3);
	pN=pN->next;
	pN->next=new Node(7);
	pN=pN->next;
	pN->next=new Node(11);
	pN=pN->next;
	pN->next=new Node(12);
	pN=pN->next;
	printList(start);
	
	reverse_list(start);
	printList(pN);

	system("pause");
	return 0;
}
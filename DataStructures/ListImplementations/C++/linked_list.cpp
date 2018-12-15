#include<bits/stdc++.h>

using namespace std;


struct Node
{   int data;
	Node* next=NULL;
};

Node *head=NULL;

void insertAtPosition(int index,int value){

	Node* node= new Node();
	node->data=value;

	if(index==0){
		node->next=head;
		head=node;
		return;
	}

	Node* temp=head;

	for(int i=0;i+1<index;i++)
		temp=temp->next;

	node->next=temp->next;
	temp->next=node;
	
}
void add(int num){

	Node* node= new Node();
	node->data=num;
	

	if(head==NULL){
		head=node;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL)temp=temp->next; 
	temp->next=node;
}

void removeAtIndex(int index){
	Node* temp=head;

	if(index==0){
		head=head->next;
		return;
	}
	for(int i=0;i+1<index;i++)
		temp=temp->next;
	Node * toDelete=temp->next;
	temp->next=temp->next->next;
	delete toDelete;
}

void printList(){
	Node* temp=head;

	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}

	cout<<"\n";
}

void reverseLinkedList_iterative(){
	Node* previous = NULL;
	Node* current= head;
	
	while(current!=NULL){
		Node* temp=current->next;
		current->next=previous;
		previous=current;
		current=temp;
	}

	head=previous;
}

void  reverseLinkedList_recursive(Node * current,Node * previous){
	if(current==NULL){
		head =previous;
		return;
	}
	
	Node* temp=current->next;
	current->next=previous;
	previous=current;
	current=temp;
	reverseLinkedList_recursive(current,previous);

	
}

void reverse_print(Node* node){

	if(node==NULL)return;

	reverse_print(node->next);
	cout<<node->data<<"\n";

}




int main(){
	
	add(2); printList();
	add(4); printList();
	add(6); printList();

	reverseLinkedList_recursive(head,NULL);
	printList();
	reverse_print(head);

}
#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};

void insertAtEnding(Node* &tail, int d){
	Node* temp = new Node(d);
	tail->next = temp;
	tail = temp;
}

void insertAtHead(Node* &head, int d){
	Node* temp = new Node(d);
	temp->next = head;
	head = temp;
}

void insertAtPos(Node* &head, Node* &tail, int pos, int d){
	if(pos == 1){
		insertAtHead(head, d);
		return;
	}
	
	Node* temp = head;
	int cnt = 1;
	while(cnt < pos-1){
		temp = temp->next;
		cnt++;
	}
	if(temp->next == NULL){
		insertAtEnding(tail, d);
	}
	
	Node* nodeToInsert = new Node(d);
	nodeToInsert->next = temp->next;
	temp->next = nodeToInsert;
}

void print(Node* &head){
	if(head == NULL ){
		cout<<"list is empty"<<endl;
	}
	if(head->next == NULL){
		cout<<head->data<<endl;
	}
	
	Node* temp = head;
	
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void reverse1(Node* &head, Node* temp, Node* prev, Node* curr){
	if(curr == NULL){
		head = prev;
		return;
	}
	
	temp = prev;
	prev = curr;
	curr = curr->next;
	reverse1(head, temp, prev, curr);
	prev->next = temp;
}

Node* reverse(Node* &head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	Node* temp = NULL;
	Node* prev = head;
	Node* curr = head->next;
	
	reverse1(head, temp, prev, curr);
	prev->next = NULL;

	return head;
	
//	while(curr != NULL){
//		prev -> next = temp;
//		temp = prev;
//		prev = curr;
//		curr = curr->next;
//	}
//	prev->next = temp;
//	head = prev;
//	return head;
}

//using recursion
void reverselinked(Node* &head, Node* curr, Node* prev){
	if(curr == NULL){
		head = prev;
		return;
	}
	Node* forward = curr->next;
	reverselinked(head, forward, curr);
	curr->next = prev;
}
Node* reverselist(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	reverselinked(head, curr, prev);
	return head;
}

int main(){
	Node* node1 = new Node(10);
	Node* head = node1;
	Node* tail = node1;
	
	insertAtEnding(tail, 20);
	insertAtEnding(tail, 30);
	insertAtEnding(tail, 40);
	insertAtEnding(tail, 50);
	insertAtPos(head, tail, 4, 35);
	
	print(head);
	
	head = reverse(head);
	print(head);
	
}

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

void insertAtHead(Node* &head, int d){
	Node* temp = new Node(d);
	temp->next = head;
	head = temp;
}

int getLen(Node* head){
	int cnt = 0;
	while(head!=NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

Node* findMiddle(Node* head){
	int len = getLen(head);
	cout<<len<<endl;
	int ans = len/2;
	int cnt = 0;
	Node* temp = head;
	
	while(cnt<ans){
		temp = temp->next;
		cnt++;
	}
	return temp;
}

//optimised code
Node* getMiddle(Node* head){
	if(head == NULL || head->next == NULL)
	return head;
	
	if(head->next->next==NULL)
	return head->next;
	
	Node* fast = head->next;
	Node* slow = head;
	while(fast != NULL){
		fast = fast->next;
		if(fast != NULL){
			fast = fast->next;
		}
		slow = slow->next;
	}
	return slow;
}

Node* kReverse(Node* head, int k){
	Node* curr = head;
	int count = 0;
	while(curr!=NULL && count<k){
		curr = curr->next;
		count++;
	}
	if(count<k){
		return head;
	}
	
	//step-1 Reversing K Nodes
	curr = head;
	Node* next = NULL;
	Node* prev = NULL;
	count=0;
	
	while(curr != NULL && count<k){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	//step-2 Recurse on remaining list
	if(next != NULL){
		head->next = kReverse(next, k);
	}
	
	//step-3 return new head;
	return prev;
}

void print(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<< temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	
	int k;
	cin>>k;
	
	Node* node1 = new Node(10);
	Node* head = node1;
	Node* tail = node1;
	
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);
	insertAtHead(head, 60);
	insertAtHead(head, 70);
	insertAtHead(head, 80);
	insertAtHead(head, 90);
	insertAtHead(head, 100);
	
	print(head);
	cout<<findMiddle(head)->data<<endl;
	cout<<getMiddle(head)->data<<endl;
	
	head = kReverse(head, k);
	print(head);
	
}

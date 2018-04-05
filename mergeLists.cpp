

#include<bits/stdc++.h>
#define F(i,h) for(Node* i = h;i!=NULL;i=i->next)
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
struct Node {
	int data;
	Node* next;
};

Node* list1;
Node* list2;
Node* head;

Node* makeNode(int x){
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void printList(Node * h){
	if(h==NULL) {
		cout<<"List Empty!";
		return;
	}
	F(i,h)
		if(i->next)
			cout<<i->data<<"  ->  ";
		else
			cout<<i->data<<endl;
}
Node* insertNode(Node *h,int x){
	if(h==NULL)
		return h=makeNode(x);
	Node* p = h;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next =makeNode(x);
	return h;
}

Node* findMid(Node* h){
	if(!h) return h;
	Node* q;
	Node* p;
	q=p=h;
	while(q->next && q->next->next){
		p = p->next;
		q = q->next->next;
	}
	return p;
}

int main(){
	f(i,0,7)
		list1 = insertNode(list1,3*i+7);
	printList(list1);
	cout<<findMid(list1)->data;


}
/*Node* mergeLists(Node* list1,Node* list2){
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;
	Node* list = NULL;
	if(list1->data <= list2->data)
		list->next = mergeLists(list1->next,list2);
	else
		list->next = mergeLists(list1,list2->next);
	return list;
	}

*/
#include<bits/stdc++.h>
#define MAXN 20
#define f(i,a) for(Node* i=a;i!=NULL;i=i->next)
using namespace std;

struct Node{
	int value;
	Node* next;
};

Node* head;
Node*head2;
Node* phead2=head2;

Node* makeNode(int x){
	Node* p= new Node;
	p->value =x;
	p->next =NULL;
	return p;
}


void printfListNode(Node* h){
	if(h==NULL) cout<<"Empty!";
	f(i,h)
		cout<<i->value<<"   ";
	cout<<endl;
}



void insertNode(Node**h,int x){
	Node* h = head;
	Node*p =makeNode(x);
	if(h==NULL)
		return;
	Node*q=h;
	while(q->next!=NULL){
			q=q->next;
	}
	q->next=p;
	return ;
}


Node* findNode(Node*h,int x){
	if(h==NULL) return NULL;
	f(i,h)
		if(i->value==x) return i;
	return NULL;
}


Node* removeNode(Node*h,Node*p){
	Node*q=h;
	if(h==p) {
			h=h->next;
			delete p;
			return h;}
	if(h==NULL||p==NULL)
		return h;
	while(q->next!=p){
		q=q->next;
		if(q==NULL) break;
	}
    if(q != NULL){
        p->next = q->next;
        delete p;
    }
    return h;
	p->next=q->next;
	delete p;
	return h;
}
int Sum_i(Node*h,Node*i){
	int s=0;
	f(j,i)
		s+=j->value;
	return s;
}


Node* splitLinkerList(Node*h){
	int minS=999999;
	if(!h) return NULL;
	Node*pos= new Node;
	int sumLinker = Sum_i(h,h);
	f(i,h){
		if(abs(sumLinker-2*Sum_i(h,i)) < minS)
		{
			minS=abs(sumLinker-2*Sum_i(h,i));
			pos=i;
		}
	}
	return pos;
}


int main
	Node* p =head;
	for(int i=1;i<MAXN;i++)
		insertNode(p,rand()%10);
}
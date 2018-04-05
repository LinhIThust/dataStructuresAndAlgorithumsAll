#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* pre;
};
Node* top;

Node* push(Node* t,int x){
	Node* p = new Node;
	p->data =x;
	p->pre = t;
	t = p;
	return t;
}

void PUSH(int x){
	Node* p = new Node;
	p->data = x;
	p->pre = top;
	top =p;
}
void push1(Node**top,int x){
	Node*p =new Node;
	p->data =x;
	p->pre = *top;
	*top = p;
}

int pop(){
	if(top==NULL) return -1;
	Node* temp= top;
	int x = top->data;
	top=top->pre;
	delete(temp);
	return x;


}
int main(){
	Node* p = top;
	for(int i = 0;i<11;i++)
		push1(*p,i);
	for(int i = 0;i<9;i++)
		cout<<pop()<<endl;
}
#include<bits/stdc++.h>
struct Node{
	int id;
	Node* left;
	Node* right;
};
Node* root;

Node*makeNode(int v){
	Node* p =new Node;
	p->id =v;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void insertTree(Node* p,int x){
	Node* q = p->left;
	if(q ==NULL){
		p->left = makeNode(x);
		return ;
	}
	while(q->right!= NULL)
		q=q->right;
	q->right=makeNode(x);

}
Node* findNode(Node* p,int x){
	if(p==NULL) return NULL;
	if(p->id == x) return p;
	Node*q = p->left;
	while(q!=NULL){
		Node*h=findNode(q,x);
		if(h!=NULL) return h;
		q=q->right;
	}
	return NULL;
}
void printfTree(Node*p){
	if (p ==NULL) return ;
	printf("%d    ",p->id);
	Node*q=p->left;
	while(q!=NULL){
		printfTree(q);
		q=q->right;
		printf("\n");
	}
}
int countNode(Node* p){
	int count =1;
Node*q = p->left;
while(q !=NULL){
	count=count+countNode(q);
	q=q->right;
	}
return count;
}
int countLeaves(Node*p){
	int count=0;
	if(p ==NULL) return 0;
	Node* q= q->left;
	if( q==NULL) return 1;
	while(q!= NULL){
		count=+countLeaves(q);
		q=q->right;
	}
	return count;
}
void preOrder(Node*q){

      }
 int depth(Node*r,Node*p){
 	int c=0;
 	if(r==NULL) return -1;
	if( r == p) return 0;
	Node*q=r->left;
	while(q!=NULL){
		int d =depth(q,p);
		if(d>=0) return d+1;
		q=q->right;

	}
	return -1;
}

int main(){
	root = makeNode(10);
	insertTree(root,1);
	insertTree(root,6);
	insertTree(root,7);
	Node*f1=findNode(root,1);
	insertTree(f1,8);
	insertTree(f1,4);
	Node*f2=findNode(f1,4);
	insertTree(f2,5);
	insertTree(f2,0);
	Node*f3=findNode(f2,5);
	printfTree(root);
	printf(" ==  %d",depth(root,f3));
}
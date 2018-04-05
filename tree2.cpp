#include<bits/stdc++.h>
#define f(i,a) for(Node*i = a;i!=NULL;i=i->right)
//#define f(i,a)


struct Node{
	int id;
	Node* left;
	Node* right;
};
Node* root;
//---------------------------


Node* makeNode(int x){
	Node* p= new Node;
	p->id =x;
	p->left=NULL;
	p->right=NULL;
	return p;

}
//--------------------------


void insertTree(Node*p,int x){
	if  (p == NULL) {
		p = makeNode( x );
		return;
	}
	Node* q=p->left;
	if(q==NULL) {
		p->left = makeNode(x);
		return;
	}
	while(q->right !=NULL){
		q=q->right;
	}
	q->right =makeNode(x);
}


//----------------------------


Node* findNode(Node*p,int x){
	if(p==NULL) return NULL;
	if(p->id==x) return p;

	Node*q = p->left;

	while(q!=NULL){
		Node*h =findNode(q,x);
		if(h!=NULL) return h;
		q=q->right;
	}
return NULL;
}

//----------------
void printfTree(Node*p){
	if(p==NULL) return;
	printf("%d   ",p->id);
	f(i,p->left){
		printfTree(i);
	}

}
//----------------------------

void MidVisit(Node* r) {
	if (r == NULL) return;
	Node* p = r->left;
	MidVisit(p);
	std::cout << "Visit " << r->id << std::endl;
	if (p == NULL) return;
	f(i,p->right)
		MidVisit(i);
}
//----------------------------
int countLeaves(Node*p){
	if(p==NULL) return 0;
	Node*q=p->left;
	int c=0;
	if(q==NULL) c=1;
	f(i,p->left){
		c+=countLeaves(i);
	}
	return c;
}


int countNode(Node*p){
	if(p==NULL) return 0;
	int c=1;
	Node*q=p->left;
	f(i,p->left)
		c+=countNode(i);

	return c;
}



int depth(Node*p,Node*q){
	if(q==NULL||p==NULL) return 0;
	if(q==p) return 1;
	f(i,p->left){
		int h = depth(i,q);
		if(h!=0) return h+1;
	}
	return 0;
}



int high(Node*p){
	if(p==NULL) return 0;
	int c=0;
	f(i,p->left)
		c=std::max(c,high(i));

	return c+1;

}



void enterTree(){
root =makeNode(10);
	insertTree(root,11);
	insertTree(root,1);
	insertTree(root,3);
//---------------------
//std::cout << root << std::endl;
Node*f11=findNode(root,11);
//std::cout << f11 << std::endl;
	insertTree(f11,5);
	insertTree(f11,4);
//---------------------

Node*f13=findNode(root,3);
	insertTree(f13,8);
	insertTree(f13,2);
	insertTree(f13,7);
//-----------------------
Node*f21 = findNode(f11,4);
	insertTree(f21,6);
	insertTree(f21,9);
}



int main(){
enterTree();
//printfTree(root);
MidVisit(root);
printf("\n");
printf("Count Node =%d\n",countNode(root));
printf("Count Leaves =%d\n",countLeaves(root));
printf("Do xau cua nut %d =%d\n",9,depth(root,findNode(root,9)));
printf("High of %d=%d\n",10,high(findNode(root,10)));
//std::cout << root->id;
}
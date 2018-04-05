#include<stdio.h>
#define f(i,r) for(Node* i=r;i!=NULL;i=i->right)
struct Node{
    int value;
    Node* right;
    Node* left;
};

Node* root;

void printfTree(Node* r){
    if(r==NULL) {
            printf("Cay rong");
            return;
            }
    printf("%d",r->value);
    f(i,r->left){
        printfTree(i);
        printf("\n");
    }
}
void printTree2(Node* r){
    if(r == NULL) return;
    printf("Nut %d: ",r->value);
    Node* p = r->left;
    while(p != NULL){
        printf("%d ",p->value);
        p = p->right;
    }
    printf("\n");

    p = r->left;
    while(p != NULL){
        printTree2(p);
        p = p->right;
    }
}


Node* makeNode(int x){
    Node * p = new Node;
    p->value = x;
    p->left=NULL;
    p->right=NULL;
    return p;
}




void insertTree(Node*r,int x){
    if(r==NULL){
        r=makeNode(x);
        return;
    }
    Node*q =r->left;
    if(q==NULL){
        r->left=makeNode(x);
        return;
    }
    while(q->right!=NULL){
        q=q->right;
    }
    q->right=makeNode(x);
}


Node* findNode(Node*r,int x){
        if(r==NULL)
            return NULL;
        if(r->value==x) return r;
        Node* p=r->left;
        while(p!=NULL){
            Node*q=findNode(p,x);
            if(q!=NULL) return q;
            p=p->right;
        }
        return NULL;
}

int main(){
    root=makeNode(9);
    insertTree(root,1);
    insertTree(root,2);
    insertTree(root,3);
    insertTree(root,4);

    //tao nut cua 2
    Node* p=findNode(root,2);
    insertTree(p,21);
    insertTree(p,22);
    insertTree(p,23);
    //
    Node* p1=findNode(root,21);
    insertTree(p1,211);
    insertTree(p1,212);

    Node*p2=findNode(root,3);
    insertTree(p2,31);
    insertTree(p2,32);

   printTree2(root);
}



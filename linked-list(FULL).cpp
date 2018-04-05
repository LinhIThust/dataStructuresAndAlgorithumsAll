

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* head;
Node* head2;
Node* head3;
Node* headChan;
Node* headLe;
void printList(Node* h){
    Node* p = h;
    while(p != NULL){
        printf("%d ",p->value);
        p = p->next;
    }
}

Node* makeNode(int x){
    Node* q = new Node ;
    q->value = x;
    q->next = NULL;
    return q;

}
Node* insertFirst(Node*h ,int x){
    Node* q = makeNode(x);
    if( h==NULL)
        return q;
    Node*temp = h;
    h=q;
    q->next=temp;
    return h;
}
Node* insertLast(Node* h, int x){
    Node* q = makeNode(x);
    if(h == NULL) return q;// tinh huong ngoai le (dac biet)

    // time phan tu cuoi cung cua danh sach
    Node* p = h;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
    return h;
}
Node* insertLastRecursive(Node* h, int x){
    if(h == NULL){
        return makeNode(x);
    }
    h->next = insertLastRecursive(h->next,x);
    return h;
}
int count(Node* h){
    int k = 0;
    for(Node* p = h; p != NULL; p = p->next){
        k = k + 1;
    }
    return k;
}
int countRecursive(Node* h){
    if(h == NULL) return 0;
    return 1 + countRecursive(h->next);
}
Node* find(Node*h, int x){
    if(h == NULL) return NULL;
    for(Node* p = h; p != NULL; p = p->next){
        if(p->value == x) return p;
    }
    return NULL;
}

Node* removeRecursive(Node* h, Node* p){
    if(h == NULL) return NULL;
    if(p == NULL) return h;
    if(h == p){
        h = h->next;
        delete p;
        return h;
    }else{
        h->next = removeRecursive(h->next,p);
    }
    return h;
}

Node* remove(Node* h, Node* p){
    if(h == NULL || p == NULL) return h;
    if(h == p){
        h = h->next;
        delete p;
        return h;
    }
    Node* q = h;
    while(q->next != p){
        q = q->next;
        if(q == NULL) break;
    }
    if(q != NULL){
        q->next = p->next;
        delete p;
    }
    return h;
}

Node* concat(Node* h1, Node* h2){
    Node* q = h1;
    if(h1 == NULL){return h2;}
    if(h2 == NULL) return h1;
    while(q->next != NULL)
        q = q->next;
    q->next = h2;
    return h1;
}
//tao 2 list:1 lít toan so chăn,1 list so le
void OddEven(){
    Node* p    = head;
    int soChan=0,soLe=0;
    while(p!=NULL){
        if(p->value %2 == 0){
            headChan=insertLast(headChan,p->value);
            soChan++;
        }
        else{
            headLe=insertLast(headLe,p->value);
            soLe++;
        }
        p=p->next;
    }
    printf("so so chan la:%d\n",soChan);
    printf("so so le la  :%d\n",soLe);
}

//loai so chan ra khoi list
Node* OddList(Node*h){
    if(h->value %2 == 0)
        h=h->next;
    Node* p= h;
    while(p!=NULL) {
        if((p->next)->value %2==0){
            Node*temp= p->next;
            p->next=temp->next;
            delete temp;
        }
        p=p->next;
    }
    return h;
}
Node*OddListIndex(Node* h){
    Node* temp =h;
    h=temp->next;
    delete temp;
    Node* p= h;
    for(p=h->next;p!=NULL;p=p->next){
        Node* temp=p->next;
        if(temp==NULL) return h;
        p->next=temp->next;
        delete temp;
    }
    return h;
}
//noi 2 danh ssach giam dan->giam dan
Node* merge(Node*l1,Node*l2){
    if(!l2) return l1;
	else if( !l1 ) return l2;

	Node*l = NULL;
	if( l1->value < l2->value ){
		l = l1;
		l->next = merge(l1->next, l2);
	}
	else{
		l = l2;
		l->next = merge(l1, l2->next);
	}
	return l;

    }
//noi 2 day :d1 day tang dan.d2 day giam dan -> giam dan!
Node* giamDan(Node*h1,Node*h2){
    Node*temp1=new Node;
    for(Node*p1=h1;p1!=NULL;p1=p1->next){
        for(Node*p2=h2;p2!=temp1;p2=p2->next){
            if(p1->value > p2->value){
                Node* temp=p1;
                p2=temp;
                p2->next=temp>n
            }

        }
    }
    return h2;
}
int main(){
    for(int i =10;i<100;i+=3)
        head =insertLast(head,i);
    for(int i =100;i>5;i-=12)
        head2 =insertLast(head2,i);
    //for(int i =100;i>1;i=i-12)
    //    head2 =insertLast(head2,i);
    printList(head);
    printf("\n"),
    printList(head2);
    printf("\n");
    //head3=merge(head2,head);
    //printList(head3);
    printList(giamDan(head,head2));
    //head2
    /*printf("So phan tu cua danh sach la %d\n",countRecursive(head));
    printf("ca phan tu le cua day la:");
    printList(OddListIndex(head));
   /* printList(head);
    OddEven();
    printList(headChan);
    printf("\n");
    printList(headLe);
 /*   printList(head);
    Node* h1 = NULL;
    Node* h2 = NULL;
    //for(int i = 1; i <= 10; i++)
    //    h1 = insertLast(h1,i);

    for(int i = 1; i <= 10; i++)
        h2 = insertLast(h2,i*100);

    h1 = concat(h1,h2);

    printList(h1);
*/

}


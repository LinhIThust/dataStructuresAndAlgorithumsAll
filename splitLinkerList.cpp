#include<bits/stdc++.h>
using namespace std;
#define f(i,h) for(Node* i= h;i!=NULL;i=i->pNext)

struct Node{
	int val;
	Node* pNext;
};
int Sum_i(Node*h,Node*i){
	int s=0;
	f(j,i)
		s+=j->val;
	return s;
}
Node* splitLinkerList(Node* h){
	int minS=999999;
	if(!h) return NULL;
	Node*pos=h;
	int sumLinker = Sum_i(h,h);
	f(i,h){
		if(abs(sumLinker-2*Sum_i(h,i))<minS)
		{
			minS=abs(sumLinker-2*Sum_i(h,i));
			pos=i;
		}
	}
	return pos;
}
int main(){







}
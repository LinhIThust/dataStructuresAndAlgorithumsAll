#include<bits/stdc++.h>

using namespace std;
/*
****solove :print maxDecrementalSequence***
-var finish: is end of DecrementalSequence
-maxn	   : max number Decrem in Array;

*/

void maxDecrementalSequence(int A[],int n){
	cout<<"maxDecrementalSequence:";
	int finish;
	int maxn=0,c=0;
	if(n==1) {
		cout<< A[0];
		return;
	}
	for(int i =0;i<n;i++){
		if(A[i]> A[i+1])
			c++;
		else{
			if(c> maxn){
				maxn=c;
				finish = i;
				c=0;
			}
		}
	}
	for(int i= finish-maxn;i<=finish;i++)
		cout<<A[i]<<"  ";
}
int main(){
	int A[1]={1};
	maxDecrementalSequence(A,1);

}
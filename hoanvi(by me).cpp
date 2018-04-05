#include<stdio.h>
#define MAX 1000
int n;
int a[MAX];
int count=0;
bool mark[MAX];

bool check(int v,int i){
	return !mark[v];
	}

void printSolution(){
count++;
printf("to hop thu %d la:",count);
for(int i =1;i<=n;i++){
	printf("%5d",a[i]);
	}
printf("\n");
}

void TRY(int i){
	int v;
	for ( v=1;v<=n;v++){
	if(check(v,i)){
		a[i]=v;
		mark[v] = true;
		if(i == n) printSolution();
		else{
			TRY(i+1);
			}
		mark[v]= false;
		}
	}
}
int main(){
	n=5;
for(int i =1;i<=n;i++) mark[i] = false;
TRY(1);
}
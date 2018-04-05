#include<stdio.h>
#define MAX 100
int count;
int k,N;
int x[MAX];
void printSolution(){
count++;
   printf("configuration %d: ",count);
   for(int j =1;j<=k;j++) printf("%4d",x[j]);
   printf("\n");

}
void TRY(int i){
	int v;
for(v =x[i-1]+1;v<=N-k+i;v++){
	x[i] = v;
	if ( i == k) printSolution();
		else TRY(i+1);

}


}
int main(){
N=5;
k=3;
count =0;
x[0]=0;
TRY(1);


}
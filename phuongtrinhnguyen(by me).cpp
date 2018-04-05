#include<stdio.h>
#define MAX 1000
int M,n,count,s;
int x[MAX];
void printSolution(){
	count++;
	printf("configuration %d: ",count);
for(int j=1;j<=n;j++)
	printf("%5d",x[j]);
printf("\n");

}

void TRY(int i){
	for( int v =1;v <M;v ++){
		 x[i] = v;
		 s+= x[i];
		 if ( i == n ){
			if( s== M) printSolution();
		 }else{
		 TRY(i+1);
		 }
		s-=x[i];
	}

}

int main(){
count =0;
s=0;
M=9;
n=8;
TRY(1);



}
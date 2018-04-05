#include<stdio.h>
#define MAX 1000

int a[MAX];
int n;
int count;
void printSolution(){
count++;
printf("to hop thu %d la:",count);
for(int i =1;i<=n;i++){
	printf("%5d",a[i]);
	}
printf("\n");
}
bool check(int v,int i){
if(v*a[i-1] ==0 ) return true;
else return false;

}

void TRY(int i){
int v;
for( v=0;v<=1;v++){
	if(check(v,i)){
	a[i]= v;
	if(i==n) printSolution();
	else{
		TRY(i+1);
			}
		}
	}
}


int main(){
n=10;
TRY(1);
}
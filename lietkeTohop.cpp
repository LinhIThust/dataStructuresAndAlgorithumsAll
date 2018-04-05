#include <stdio.h>
#define MAX 100
int k;
int n;
int x[MAX];
int count;
void printSolution(){
    count++;
    printf("configuration %d: ",count);
    for(int i = 1; i <= k; i++) printf("%d ",x[i]);
    printf("\n");
}
void TRY(int i){
    int v;
    for(v = x[i-1] + 1; v <= n-k+i; v++){
        x[i] = v;
        if(i == k) printSolution();
        else TRY(i+1);
    }
}

int main(){
    k = 7;
    n = 12;
    x[0] = 0;
    count = 0;
    TRY(1);
}

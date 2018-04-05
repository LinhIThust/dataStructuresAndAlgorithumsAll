#include <stdio.h>
#define MAX 100
int x[MAX];
int n;
int count;

void printSolution(){
    count++;
    printf("configuration %d: ",count);
    for(int i = 0; i < n; i++)
        printf("%d ",x[i]);
    printf("\n");
}
bool check(int v, int k){
    return v*x[k-1] != 1;
}
void TRY(int k){
    int v;// mandatory
    for(v = 0; v <= 1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k == n-1) printSolution();
            else{
                TRY(k+1);
            }
        }
    }
}
int main(){
    n = 3;
    count = 0;
    TRY(0);
}

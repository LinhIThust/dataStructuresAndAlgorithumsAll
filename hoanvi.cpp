#include <stdio.h>

int n;
int x[100];
int count;
bool mark[100];
int  giaithua(int n){
if(n==1) return 1;
    else  return n*giaithua(n-1);
}
void printSolution(){
    for(int i =1 ; i <= n; i++) printf("%d",x[i]);
    printf("\n");
}
bool check(int v, int i){
    return !mark[v];
}
void TRY(int i){
    int v;
    for(v = 1; v <= n; v++){
        if(check(v,i)){
            x[i] = v;
            mark[v] = true;
            if(i == n) printSolution();
            else{
                TRY(i+1);
            }
            mark[v] = false;// recover
        }
    }
}
int main(){
    scanf("%d",&n);
    printf("%d\n",giaithua(n));
    for(int v = 1; v <= n; v++) mark[v] = false;
    TRY(1);
}

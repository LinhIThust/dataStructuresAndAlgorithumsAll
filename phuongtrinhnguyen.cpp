#include <stdio.h>

int n;
int M;
int x[100];
int S;
int count;
void printSolution(char* fn){
    FILE* f = fopen(fn,"w");
    count++;
    fprintf(f,"configuration %d: ",count);
    for(int i = 1; i <= n; i++)
        fprintf(f,"%d ",x[i]);
    //fprintf(f,"");
   fclose(f);
}
void TRY(int i){
    int v;
    for(v = 1; v <= M; v++){
        x[i] = v;
        S += x[i];// update incrementally
        if(i == n){
            if(S == M) printSolution("pt_nguyen.html");
        }else{
            TRY(i+1);
        }
        S -= x[i];// recover trang thai

    }
}

void newTry(int m, int n){
    int i;
    if(n == 1){
        x[n] = m;
        printSolution("pt_nguyen.html");
    }else{
        for(i = 1; i <= m-n+1; i++){
            x[n] = i;
            newTry(m-i,n-1);
        }
    }
}

int main(){
    M = 6;
    n = 1;
    S = 0;
    count = 0;
    TRY(1);
    //newTry(M,n);
}

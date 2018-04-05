#include <stdio.h>

#define MAX 1000000
int a[MAX];
int n;

void readData(char* fn){
    FILE* f = fopen(fn,"r");
    fscanf(f,"%d",&n);// doc gia tri cua n
    for(int i = 0; i < n; i++)
        fscanf(f,"%d",&a[i]);
    fclose(f);
}
void algo1(){
    int max = -1000000;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int s = 0;
            for(int k = i; k <= j; k++)
                s += a[k];
            if(s > max) max = s;
            //printf("trong so day con(%d : %d) la %d, max = %d\n",i,j,s,max);
        }
    }
    printf("result1 = %d\n",max);
}

void algo2(){
    int max = -10000000;
    for(int i = 0; i < n; i++){
        int s = 0;
        for(int j = i; j < n; j++){
            s = s + a[j];
            if(s > max) max = s;
        }
    }
    printf("result2 = %d\n",max);
}

void algo3(){
    int max = -10000000;
    int s = a[0];
    max = s;
    for(int i = 1; i < n; i++){
        if(s > 0) s = s + a[i];
        else s = a[i];
        if(s > max) max = s;
    }
    printf("result3 = %d\n",max);
}
int main(){
    readData("dayso-100000.txt");
    //algo1();
    //algo2();
    algo3();
}

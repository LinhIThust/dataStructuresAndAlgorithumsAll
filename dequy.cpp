#include <stdio.h>

int f(int n){
    if(n == 0) return 1;
    return f(n-1) + n;
}
int main(){
    printf("%d",f(30));
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define f(i,a,b) for(int i=a;i<b;i++)


int a[MAX];
FILE*f=fopen("sort_op2.txt","w");


void randomData(char* fn,int n){
    FILE* f=fopen(fn,"w");
    f(i,0,n){
        fprintf(f,"%d ",rand()%10);
    }
    fclose(f);
}



void readFile(char* fn,int*p){
    FILE* f=fopen(fn,"r");
    int i=0;
    while(1){
        fscanf(f,"%d",p+i);
        if(feof(f)){
            break;
        }
        i++;
    }
    fclose(f);
}



void printf_op(int c,int*p){
    fprintf(f, "buoc thu %d: ",c);
    f(i,0,MAX)
            fprintf(f,"%d  ",*(p+i));
        fprintf(f,"\n");
}

void insertionSort(int* p){
    fprintf(f,"thuat toan insertionSort!!\n");
    int c=0;
    f(i,1,MAX){
        int last =*(p+i);
        int j=i;
        while(j>0 && *(p+j-1)>last){
            *(p+j)=*(p+j-1);
            j--;
        }
        *(p+j)=last;
        c++;
        printf_op(c,p);
    }
fclose(f);
}

void selectionSort(int* p){
    fprintf(f,"thuat toan selectionSort!!\n");
    int c=0;
    f(i,0,MAX){
        int min =i;
        f(j,i+1,MAX){
            if(*(p+j)<*(p+min)){
               min=j;
            }
        }
         int temp =*(p+i);
                *(p+i)=*(p+min);
                *(p+min)=temp;
        c++;
        printf_op(c,p);
    }
 fclose(f);
}


void bubleSort(int*p){
    fprintf(f,"thuat toan bubleSort!!!\n");
    int c=0;
    bool check;
    do{
         check=false;
         f(i,0,MAX){
             if(*(p+i)>*(p+i+1)){
                int temp = *(p+i);
                *(p+i)= *(p+i+1);
                *(p+i+1)=temp;
                check =true;
             }
         }
    c++;
    printf_op(c,p);
    }while(check);
fclose(f);
}
int main(){
    randomData("sort_ip2.txt",MAX);
    int* p;
    p=&a[0];
    readFile("sort_ip2.txt",p);
    selectionSort(p);
    insertionSort(p);
    bubleSort(p);


}

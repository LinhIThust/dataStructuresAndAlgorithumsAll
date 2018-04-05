 #include<bits/stdc++.h>
#include<time.h>
#define f(i,a,b) for(int i=a;i<b;i++)
#define MAX 10000

int a[MAX];



void randomData(char*fn){
    FILE* f=fopen(fn,"w");
    f(i,0,MAX)
        fprintf(f,"%d ",50-rand()%100);
    fclose(f);
    }


void readFile(char* fn,int* fa){
    FILE * f =fopen(fn,"r");
    int i=0;
    while(1){
        fscanf(f,"%d",fa+i);
    if(feof(f)){
        break;
        }
    i++;
    }
    fclose(f);
}


void insertionSort(char *fn,int *p){
    FILE* f= fopen(fn,"w");
    int c=0;
    f(i,1,MAX){
        int last =*(p+i);
        int j=i;
        while(j>0 && *(p+j-1)>last){
            *(p+j) =*(p+j-1);
            j--;
        }
        *(p+j) = last;
        c++;
        fprintf(f, "buoc thu %d: ",c);
        f(i,0,MAX)
            fprintf(f,"%d  ",*(p+i));
        fprintf(f,"\n");

        }
    fclose(f);
}


void selectionSort(char* fn,int* p){
    int c=0;
    FILE* f= fopen(fn,"w");
    f(i,0,MAX){
        int min=i;
        f(j,i+1,MAX){
            if(*(p+min) > *(p+j)){
                min =j;
                }
            }
        int temp =*(p+min);
        *(p+min)=*(p+i);
        *(p+i)= temp;
        c++;
        fprintf(f, "buoc thu %d: ",c);
        f(i,0,MAX)
            fprintf(f,"%d  ",*(p+i));
        fprintf(f,"\n");
    }
    fclose(f);
}



void bubleSort(char* fn,int *p){
    int c=0;
    bool check;
    FILE* f= fopen(fn,"w");
    do{
    check = false;
    f(i,0,MAX){
        if(*(p+i)> *(p+i+1)){
            int temp = *(p+i);
            *(p+i)=*(p+i+1);
            *(p+i+1) =temp;
            check=true;
            }
        }
    c++;
    fprintf(f, "buoc thu %d: ",c);
    f(i,0,MAX)
        fprintf(f,"%d  ",*(p+i));
    fprintf(f,"\n");
    }
    while(check);
    fclose(f);
}



int main(){
    int* p;
    p=&a[0];
    randomData("sortin.txt");
    readFile("sortin.txt",p);
    //insertionSort("sortout1.txt",p);
    //selectionSort("sortout2.txt",p);
    bubleSort("sortout3.txt",p);
    //clockid_t clock();



}

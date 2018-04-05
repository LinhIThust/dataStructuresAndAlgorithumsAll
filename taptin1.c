#include<stdio.h>
#define MAX 10000
#define for1(n) for(i=0;i<n;i++) //dinh nghia vong for
//tao 1 file de doc
	int n,m,i;

void readFile(char* fn){
FILE* f=fopen(fn,"r");
fscanf(f,"%d",&n);
fscanf(f,"%d",&m);
fclose(f);
//tao 1 file de ghi
}
void writeFile(char* fn){
FILE* f = fopen(fn,"w");
fprintf(f,"%d\n%d\n",n,m);
//for(i=0;i<n;i++)
for1(m)
	fprintf(f,"hello %d\n",i+1);
fclose(f);
}

int main(){
readFile("vd1.txt");
writeFile("vd1.out");
}
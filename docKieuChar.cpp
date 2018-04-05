
#include<bits/stdc++.h>
using namespace std;
int sizeoffile1(FILE *file){
	fseek(file, 0, SEEK_END);
	int  size = ftell(file);
	//fseek(file, 0, SEEK_SET);

	return size;
}
int sizeoffile2(FILE *file){
	char ch;
	int count =0;
	while(1){
		ch=fgetc(file);//DOC TUAN TU TUNG KI TU
		if(feof(file)){
			break;
		}
		count++;
	}
	return count;
}
int main(){
FILE * p1= fopen ("vd2.txt" , "r");
FILE * p2= fopen ("vd3.txt" , "w");
cout<<sizeoffile2(p1)<<endl;
fclose(p1);
fclose(p2);
}
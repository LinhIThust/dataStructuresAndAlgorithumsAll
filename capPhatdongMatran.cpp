#include<bits/stdc++.h>
using namespace std;

struct Matrix{
	int row;
	int colum;
	int **matrix;
};

Matrix setMatrix(int R,int L){
	Matrix temp;
	temp.colum=L;
	temp.row=R;
	temp.matrix=NULL;
	return temp;
}

void allocMatrix(int ***A,int row,int colum){
	*A= new int*[row];
	for(int i =0;i<row;i++)
		(*A)[i] = new int[colum];
}
void creatData(ofstream &ofs,int numberMatrix){
	int n = 3+rand()%10;
	int m=  3+rand()%10;
	for(int k=0;k<numberMatrix;k++){
		ofs<<n<<" "<<m<<endl;
		for(int i =0;i<n;i++){
			for(int j =0;j<m;j++){
				ofs<<10+rand()%10 <<"  ";
			}
			ofs<<endl;
		}
		ofs<<endl;
	}
}

void inputMatrix(Matrix A,ifstream &ifs){
	for(int i =0;i<A.row;i++)
		for(int j =0;j<A.colum;j++)
			ifs >> A.matrix[i][j];
}

void outputMatrix(Matrix A,string x,ofstream& ofs){
	ofs<<"Matrix "<<x<<endl;
	for(int i =0;i<A.row;i++){
		for(int j =0;j<A.colum;j++){
			ofs<<A.matrix[i][j]<<"  ";
		}
		ofs<<endl;
	}
	ofs<<endl;
}

Matrix operator +(Matrix A,Matrix B){
	Matrix C;
	C =setMatrix(A.row,A.colum);
	allocMatrix(&C.matrix,C.row,C.colum);
	for(int i =0;i<C.row;i++){
		for(int j =0;j<C.colum;j++){
			C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
		}
	}
	return C;
}
Matrix operator - (Matrix A, Matrix B){
	Matrix C;
	C =setMatrix(A.row,A.colum);
	allocMatrix(&C.matrix,A.row,A.colum);
	for(int i =0;i<C.row;i++){
		for(int j =0;j<C.colum;j++){
			C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
		}
	}
	return C;
}

int main(){
	int RN,CN;
	ofstream cfs("inputMatrix.txt");
	creatData(cfs);
	creatData(cfs);
	ifstream ifs("inputMatrix.txt");
	ofstream ofs("outputMatrix.txt");
	ifs>>RN>>CN;
	Matrix A=setMatrix(RN,CN);
	Matrix B=setMatrix(RN,CN);
	allocMatrix(&A.matrix,RN,CN);
	allocMatrix(&B.matrix,RN,CN);
	//------------------------//
	inputMatrix(A,ifs);
	inputMatrix(B,ifs);
	outputMatrix(A,"A",ofs);
	outputMatrix(B,"B",ofs);
	//--------------------//
	outputMatrix(A+B,"A+B",ofs);
	outputMatrix(A-B,"A-B",ofs);
	//-------------------//
}

#include<bits/stdc++.h>
#define MAXN 1000
using namespace std;
/*tim vi tri ma chenh lech tong 2 day la min
*tong tu 1->i la Si
*tong thu 2 la S-Si
*khi do chenh lech 2 day la abs(S-2*Si)
*Khi do chi can duyet tu 1->N va ktra  vi tri i  ma co abs(S-2*Si) la min
*DONE!!!!
*/
// ham tra ve tong S[i]:tu a0-ai;
int indexSum(int a[],int i){
	int s=0;
	for(int j=0;j<i;j++){
		s+=a[j];
	}
	return s;
}
int splitSum(int a[],int n){
	int index =0;
	int S =indexSum(a,n);
	int minS =999999;
	for(int i =0;i<n;i++){
		int checkResult =abs((S-2*indexSum(a,i)));
		if(checkResult < minS){
		minS =checkResult;
		index = i;
		}
	}
	return index;
}

int main(){
	int a[MAXN];
//khoi tao mang ngau nhien
	for(int i =0;i<MAXN;i++){
		a[i] = 15-rand()%30;
		cout<<a[i]<<"  ";
	}
	cout<<endl;
//kieu tra ket qua
	for(int i =0;i<MAXN;i++){
		cout<<"tai vi tri"<<i<<"   ";
		cout<<indexSum(a,i+1)<<"|"<<indexSum(a,MAXN)-indexSum(a,i+1)<<" | "<< abs(indexSum(a,MAXN)-2*indexSum(a,i+1));
		cout<<endl;
	}

	int pos=splitSum(a,MAXN)-1;
	cout<<"ke qua  :"<<pos;







}
#include<iostream>
using namespace std;
double pow(double x,unsigned long long int n){
	if(!n) return 1;
	if(!x) return 0;
	double temp = pow(x,n/2);
	if(n%2==0)
		return temp*temp;
	else
		return temp*temp*x;
}

int main(){
double test=1;
cout<<pow(20,100);
/*for(int i = 0;i<100;i++){
	test=test*20;
}

cout<<test;
*/
}
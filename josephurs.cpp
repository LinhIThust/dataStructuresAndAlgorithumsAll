#include<iostream>
using namespace std;

int josephur(int n,int k){
  if(n==1)
      return n;

  return (josephur(n-1,k)+k-1)%n+1;    //f(n,k)=f(n-1,k)+k%n actual formula

}
int main(){
    int n;
    int k;

    cin>>n>>k;
    cout<<josephur(n,k);

    return 0;
}

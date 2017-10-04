#include<iostream>
using namespace std;
int n,br,mesta[10000],mes;
bool A[10000];
bool isap(int a,int b){
  int i;
  for(i=a;i<b&&A[i]==A[b-i-1];i++);
  if(i==b)return true;
  return false;
}
int main(){
  cin>>n;
  int i;
  for(i=0;i<n;i++)cin>>A[i];
  if(isap(0,n)==true){cout<<"1\n";return 0;}

  cout<<"2 \n2";
  return 0;
}
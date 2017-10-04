#include<iostream>
using namespace std;

int main(){
  long long n,a[200],b[200],j,izhod,dalzina[200],min=1000,i,copy;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  for(i=0;i<n;i++){
    cin>>b[i];
  }
  for(i=0;i<n;i++){
    dalzina[i]=a[i]+b[i];
  }
  for(i=0;i<n;i++){
    if(dalzina[i]<min){
      min=dalzina[i];
    }
  }
  izhod=min;
  min=1000;
  for(i=0,j=n-1;i<=(n/2-1);i++,j--){
    b[i]=copy;
    b[i]=b[j];
    b[j]=copy;
    }
  for(i=0;i<n;i++){
    dalzina[i]=a[i]+b[i];
  }
  for(i=0;i<n;i++){
    if(dalzina[i]<min){
      min=dalzina[i];
    }
  }
  if(min>izhod){
    cout<<min;
  }else{
    cout<<izhod;
  }
  cout<<endl;
  return 0;
}
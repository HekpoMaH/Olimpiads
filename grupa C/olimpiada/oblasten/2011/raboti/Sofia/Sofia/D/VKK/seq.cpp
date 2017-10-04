#include<iostream>
using namespace std;

int main(){
  double staro,nowo=1;
  long long max=0,izhod=0;
  cin>>staro;
  while(nowo!=0){
    cin>>nowo;
    if(staro<=nowo){
      max++;
    }else{
      if(max>izhod){
        izhod=max;
      }
    max=0;
    }
    staro=nowo;
  }
  cout<<izhod+1<<endl;
  return 0;
}
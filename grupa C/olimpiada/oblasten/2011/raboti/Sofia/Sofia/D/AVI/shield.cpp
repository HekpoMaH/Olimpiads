#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int shield1[110],shield2[110];
for(int i=0;i<n;++i){
    cin>>shield1[i];
}
for(int i=0;i<n;++i){
    cin>>shield2[i];
}
int tekmi=0,min2=shield1[0]+shield2[n-1],min1=shield1[0]+shield2[0];
for(int i=1;i<n;++i){
    tekmi=shield1[i]+shield2[i];
    if(tekmi<min1){
     min1=tekmi;
    }
}
if(n%2){
  int t;
for(int i=1,j=n-2;i!=j;++i,--j){
    tekmi=shield1[i]+shield2[j];
    if(tekmi<min2){
     min2=tekmi;
    }
t=j;
}
 tekmi=shield1[--t]+shield2[t];
    if(tekmi<min2){
     min2=tekmi;
    }
}
if(!(n%2)){
for(int i=1,j=n-2;i<j;++i,--j){
    tekmi=shield1[i]+shield2[j];
    if(tekmi<min2){
     min2=tekmi;
    }
}
}
if(min1>min2){
  cout<<min1;
}else{
  cout<<min2;
}
cout<<endl;
return 0;
}
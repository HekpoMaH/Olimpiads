#include<iostream.h>
using namespace std;
int main(){
int n,a=1,b=1,br=2,c;
cin>>n;
if(n>=1&&n<=1000){
if(n>2){
for(;br<n;br++){
c=a+b;
b=a;
a=c;
}
cout<<a;
}
else{
if(n==1||n==2){cout<<"1";}
}
}
return 0;
}

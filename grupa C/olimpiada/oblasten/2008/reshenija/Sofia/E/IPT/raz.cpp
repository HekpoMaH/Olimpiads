#include<iostream>
using namespace std;
int main(){
int n,a,b,c,max=0;
cin>>n;
if(n==1)cout<<"1 1";
else{
for(int i=1;i<=(double)n/2;i++){
if(i>max&&n%i==0&&i<a){c=i;a=n/i;b=a;max=i;}
}
cout<<c<<" "<<b;
}
return 0;
}

#include<iostream>
using namespace std;
int main(){
int v,k,n;
char a;
cin>>v>>k>>n;
for(int i=0;i<n;i++){
cin>>a;
if(a=='+')v+=k;
if(a=='-')v-=k;
}
cout<<v;
return 0;
}

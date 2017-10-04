#include<iostream>
using namespace std;
int main(){
int n,a,b=0,min;
cin>>n;
for(int i=0;i<n;i++){
cin>>a;
b+=a;
if(a<min)min=a;
}
b-=min;
b++;                                          
cout<<b;
return 0; 
}                  

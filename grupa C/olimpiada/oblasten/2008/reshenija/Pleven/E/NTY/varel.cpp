#include<iostream>
using namespace std;
int main(){
    char z;
    int sum=0,i,v,k,n;
    cin>>v>>k>>n;
    for(i=1;i<=n;i++)
{cin>>z;
sum=v+k;
if(z='+')sum=sum+k;
if(z='-')sum=sum-k;}
cout<<sum<<endl;    
    
       
        return 0;}              

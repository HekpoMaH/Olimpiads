#include<iostream>
using namespace std;
int main(){
    int y,i,n,a[7],sum=0,min=20;
    cin>>n;
    for(i=0;i<=n-1;i++){
        cin>>a[i];
        if(a[i]<min)min=a[i];
        sum=sum+a[i];}
        sum=sum-min;
        sum=sum+1;
        cout<<sum<<endl;
        return 0;}              

#include<iostream>
using namespace std;
int main ()
{
    int sum=0,n,a,min;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        sum=sum+a;
        if(min>a){
                  min=a;
                  } }
        
        cout<<(sum-min)+1;
        return 0;
}
                     
                        

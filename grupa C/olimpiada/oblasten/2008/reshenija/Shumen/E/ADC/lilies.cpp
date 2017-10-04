#include<iostream>
using namespace std;
int main ()
{
   int n,i,br=0,a,mn=21,c;
   cin>>n;
   for(i=1;i<=n;i++)
   {
        cin>>a;
        if(a<mn)mn=a;
        br+=a;
    }
    c=br-(mn-1);
    cout<<c<<endl;
}    

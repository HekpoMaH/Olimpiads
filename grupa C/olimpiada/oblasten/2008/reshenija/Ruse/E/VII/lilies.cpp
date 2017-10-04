#include<iostream>
using namespace std;
int main ()
{
    int n,i,a,m=0,v=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
                    cin>>a;
                    if(a>m && a!=n) m=a;
                    if(a>v && a!=m && a!=n) v=a;
                     
}
cout<<m+v+1<<endl;
                    
                    
                     return 0;
                     }
                     
                     

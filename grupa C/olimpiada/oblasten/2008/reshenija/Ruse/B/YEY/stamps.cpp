#include<iostream>
using namespace std;
int main()
{
    int s,n,i,p,min,q,mi;
    cin>>s>>n;
    int a[n];
    for(i=0; i<n; i++)
    cin>>a[i];
    
    for(i=0; i<n; i++)
    for(p=0; p<(n-1); p++)
    if (a[p]<a[p+1]) swap(a[p],a[p+1]);
    
    mi=0; q=s;
             for(i=0; i<n; i++)
             {
                      if(q%a[i]==0) {mi+=q/a[i]; break;}
                      else if(q>a[i]) {mi+=q/a[i];  q-=a[i]*(q/a[i]);}
                      
              }
    
    min=mi;
    for(p=1; p<n; p++)
    {
             mi=0; q=s;
             for(i=p; i<n; i++)
             {
                      if(q%a[i]==0) {mi+=q/a[i]; break;}
                      else if(q>a[i]) {mi+=q/a[i];  q-=a[i]*(q/a[i]);}
                           
              }
     if (mi<min) min=mi;
     }
    cout<<min;
    cout<<endl;
    return 0;}

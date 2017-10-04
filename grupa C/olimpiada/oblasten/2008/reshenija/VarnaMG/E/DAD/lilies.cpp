#include<iostream>
using namespace std;
int main()
{
    int a[7], n, i, sbor, k, min, j;
    cin>>n;
    
    for(i=0;i<n;i++)
    cin>>a[i];   
    
    min=a[21];
    for(i=0;i<n;i++)
    {if(a[i]<min)
    min=a[i];}
    
    sbor=0;
    k=0;
    for(i=0;i<n;i++)
    sbor=sbor+=a[i];
    
    
    k=min-(min-(min-1));
    j=sbor;
    
    cout<<j-k;
   
    return 0;
}

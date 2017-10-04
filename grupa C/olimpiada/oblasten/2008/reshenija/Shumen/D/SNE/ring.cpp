#include<iostream>
using namespace std;
int a[1000000];
int main()
{
    int br3=0,e=0,i,n,k,br=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    cin>>a[i];
    while(e==0)
    for(i=0;i<n;i++)
    {
    if(a[i])br++;
    if(br==k){k=a[i];a[i]=0;br=0;br3++;}
    if(br3==n){cout<<i+1<<endl;return 0;}
    }
}

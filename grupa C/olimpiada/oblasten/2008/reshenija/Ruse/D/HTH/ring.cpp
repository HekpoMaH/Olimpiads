#include<iostream>
using namespace std;
int main()
{
    long long n,k,a[200000],z,i,br=0,j;
    cin>>n>>k;
    z=n;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(j=1;j<n;j++){
              br=0;
              for(i=1;i<=n;i++){
              if(a[i]!=0) br++;
              if(br==k){k=a[i]; a[i]=0;break;}}}
    for(i=1;i<=n;i++)
    if(a[i]!=0){cout<<a[i]<<endl;break;}
    return 0;
}

#include<iostream>
using namespace std;
int a[32][32],n,i,j,k,m,p,p1,p2,b[512],c[512],d[512];
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    for(i=0;i<n-1;i++)
    for(j=0;j<n-1-i;j++){
    b[p1]=a[i][j];p1++;}
    for(i=n-1;i>0;i--)
    for(j=n-1;j>n-1-i;j--){
    c[p2]=a[j][i];p2++;}
    for(i=0;i<p1;i++)
    if(b[i]==c[i])k++;
    if(k==p1&&p1&&k)
    {
             for(i=0;i<n;i++)
             for(j=0;j<n;j++)
             if(a[i][j]%3==0&&a[i][j]){d[p]=a[i][j];p++;}
             for(i=0;i<p-1;i++)
             cout<<d[i]<<' ';
             if(p)cout<<d[i]<<endl;
    }
    else
    {
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(i%2==0)m+=a[i][j];
        cout<<m<<endl;
    }
}

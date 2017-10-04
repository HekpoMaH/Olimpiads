#include<iostream>
using namespace std;
int countpals(int v)
{
    int pd[11]={0,9,9,90,90,900,900,9000,9000,90000,90000};
    int pp[11]={1,10,10,100,100,1000,1000,10000,10000,100000,100000};
    int d[100];
    int n=0;
    int v0=v;
    while(v!=0)
    {
        d[n]=v%10;
        v/=10;
        n++;
    }
    int r=0;
    for(int i=1;i<n;i++)r+=pd[i];
    for(int i=1;i<d[n-1];i++)r+=pp[n-2];
    int j=1;
    int k=n-2;
    while(j<k)
    {
        for(int i=0;i<d[k];i++)r+=pp[k-j-1];
        j++;
        k--;     
    }
    if(j==k)
    for(int i=0;i<d[k];i++)r++;
    int w=0;
    for(int i=n-1;i>=k+1;i--)w=10*w+d[i];
    if(j==k)w=10*w+d[k];
    for(int i=k+1;i<=n-1;i++)w=10*w+d[i];
    if(w<=v0)r++;
    //cout<<w<<endl;
    return r;
}
int main()
{
    int v;
    cin>>v;
    cout<<countpals(v)<<endl;
    return 0;
}
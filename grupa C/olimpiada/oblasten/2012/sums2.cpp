//
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool a[10001];
long long int b[110],c[110];
int main()
{
    ios::sync_with_stdio(false);
    int n,a1,b1;
    int br=0;
    cin>>n>>a1>>b1;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        if(b[i]>b1){b[i]=0;i--;n--;}
        a[b[i]]=1;
        
    }
    sort(b,b+n);
    c[0]=b[0];
    for(int i=1;i<=n;i++)
    {
        c[i]=b[i]+c[i-1];
        a[c[i-1]]=1;
        
    }
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(c[i]>b[j]){a[c[i]-b[j]]=1;c[i]=c[i]-b[j];}
        }
    }
    for(int i=a1;i<=b1;i++)
    {
        if(a[i]==1){br++;}
    }
    cout<<br<<endl;
    return 0;
}
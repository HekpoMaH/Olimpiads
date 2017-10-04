#include<iostream>
using namespace std;
int s,n,b[1000009];
int main()
{
    cin>>s>>n;
    b[1]=1;
    for(int j=2;j<=s;j++)
    {
        int t;
        if(j<=n)t=1;
        else t=j;
        for(int k=1;k<=n;k++)
        {
            int v;
            if(j-k>=1)v=b[j-k]+1;
            if(v<t)t=v;
            if(k>1)if(j%k==0)v=b[j/k]+1;
            if(v<t)t=v;
        }
        b[j]=t;
    }
    cout<<b[s]<<endl;
}

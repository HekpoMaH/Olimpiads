#include<iostream>
using namespace std;
int n,m;
int a[102],b[102];
int used[1000003];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
        b[i]+=a[i]*100;
    }
    //for(int i=1;i<=m;i++)cout<<b[i]<<endl;
    //cout<<"--------"<<endl;
    used[0]=1;
    for(int i=0;i<=1000000;i++)
    {
        if(used[i]!=0)
        {
            for(int j=1;j<=m;j++)used[i+b[j]]=1;
        }
    }
    //for(int i=0;i<=20;i++)cout<<used[i]<<" "<<i<<endl;
    //cout<<endl;
    for(int i=1;i<=1000000;i++)
    {
        if(used[i]!=0&&(i+4)%5==0)
        {
            int k=n/4;
            if(n%4!=0)k++;
            cout<<k*i/100<<" "<<k*i%100<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
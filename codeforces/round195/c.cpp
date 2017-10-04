#include<bits/stdc++.h>
using namespace std;
vector<int> v[99];
int n,a[100009],mxcnt,mxa,mxv=-1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x4e=a[i],cnt=0;
        while(x4e!=0)
        {
            if(x4e%2!=0)
            v[cnt].push_back(a[i]);
            cnt++;x4e/=2;mxcnt=max(mxcnt,cnt);
        }

    }
    for(int i=0;i<mxcnt;i++)
    {

        if(v[i].size()==0)continue;int x=v[i][0],wtf,hpr=0;
        for(int j=1;j<v[i].size();j++)x&=v[i][j];
        wtf=0;
        //cout<<i<<endl;
        if(x!=0)for(wtf=1;x%wtf==0;wtf*=2)
        {
            hpr++;//cout<<x<<" "<<wtf<<" "<<hpr<<endl;
        }
        if(hpr>mxa)mxa=hpr,mxv=i;
    }

    if(mxv==-1)
    {
        cout<<n<<endl;
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
        return 0;
    }
    cout<<v[mxv].size()<<endl;
    for(int i=0;i<v[mxv].size();i++)
    {
        cout<<v[mxv][i]<<" ";
    }
    cout<<endl;
}

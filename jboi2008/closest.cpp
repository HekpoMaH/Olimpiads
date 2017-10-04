#include<bits/stdc++.h>
using namespace std;
string a;
string b;
int n;
string a1="",a2="";
int used[100],fl;
void makeboq(int pos,int l)
{
    if(pos==n)return;
    if(l==1)
    {
        int mn=10,idx;
        for(int i=0;i<n;i++)
        {
            if(used[i]==0)
            {
                if(mn>b[i]-'0')mn=b[i]-'0',idx=i;
            }
        }
        if(mn==10)return;
        used[idx]=1;
        a1+=b[idx];makeboq(pos+1,l);
        return;
    }
    int mn=10,idx;
    for(int j=0;j<n;j++)
        {
            if(used[j]==0&&b[j]>a[pos])
            {
                if(b[j]-'0'<mn)
                mn=b[j]-'0',idx=j;
            }
        }
    if(mn!=10)
    {
        used[idx]=1;
        a1+=b[idx];
        makeboq(pos+1,l|1);
        return;
    }

    for(int j=0;j<n;j++)
        {
            if(used[j]==0&&b[j]==a[pos])
            {
                used[j]=1;a1+=b[j],makeboq(pos+1,l);
                return;
            }
        }

}
void makeless(int pos,int l)
{
    int mx=-1,idx;
    if(pos==n)
    {
        if(l==1)fl=1;
        return;
    }
    if(l==1)
    {
        for(int i=0;i<n;i++)
        {
            if(used[i]==0&&b[i]-'0'>mx)mx=b[i]-'0',idx=i;
        }
        if(mx==-1)return;
        used[idx]=1;
        a2+=b[idx];
        makeless(pos+1,l);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(used[i]==0)
        {
            if(b[i]-'0'>mx&&b[i]<a[pos])
            {
                if(pos==0&&b[i]=='0')continue;
                mx=b[i]-'0';idx=i;
            }
        }
    }
    //cout<<"Mx="<<mx<<endl;
    if(mx!=-1){
    used[idx]=1;
    a2+=b[idx];
    makeless(pos+1,l|1);return;}
    for(int i=0;i<n;i++)
    {
        if(used[i]==0)
        {
            if(b[i]==a[pos])
            {
                used[i]=1;
                a2+=b[i];
                makeless(pos+1,l);
                return;
            }
        }
    }
}
int main()
{
    cin>>a>>b;

    n=a.size();
    makeboq(0,0);
    memset(used,0,sizeof(used));
    makeless(0,0);
    if(a1.size()==n)cout<<a1<<endl;else cout<<0<<endl;
    if(a2.size()==n&&fl==1)cout<<a2<<"\n";else cout<<0<<endl;
}

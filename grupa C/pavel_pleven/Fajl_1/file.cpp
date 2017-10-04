#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int n,k,sum,m1[20005],m2[20005],m3[20005],m4[20005];
string ns[20005],ks[20005];
int fff(int first,int second)
{
    string s1=ns[first],s2=ns[second];
    int d=s1.size();
    int br=0;
    for(int i=0;i<d;i++)
    {
        if(s1[i]==s2[i])br++;
        else break;
    }
    return br+1;
}
int retnums(string s)
{
    for(int i=1;i<=n;i++)if(ns[i]==s)return i;
}
void obrabotim1()
{
    m1[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(ns[i][0]!=ns[i-1][0])m1[i]=1;
        else m1[i]=min(m1[i-1]+1,fff(i-1,i));
    }
    m2[n]=m1[n];
    for(int i=n;i>=2;i--)
    {
        if(m1[i-1]-m2[i]>1)m2[i-1]=m2[i]+1;
        else m2[i-1]=m1[i-1];
    }
    if(m2[n]>2)
    {
        m3[n]=2;
        for(int i=n;i>=2;i--)
        {
            if(m2[i-1]-m3[i]>1)m3[i-1]=m3[i]+1;
            else m3[i-1]=m2[i-1];
        }
    }
    else for(int i=1;i<=n;i++)m3[i]=m2[i];
    m4[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(m2[i]-m4[i-1]>1)m4[i]=m4[i-1]+1;
        else m4[i]=m2[i];
    }
    if(m2[n]>1)
    {
        m4[n]=1;
        for(int i=n;i>=2;i--)if(m2[i-1]-m4[i]>1)m4[i-1]=m4[i]+1;
    }
}
void resh()
{
    int num,nums,x,y;
    string s;
    num=retnums(ks[1]);
    if(num==1)sum=0;
    else sum=m4[num];
    nums=num;
    for(int i=2;i<=k;i++)
    {
        num=retnums(ks[i]);
        x=max(num,nums);y=min(num,nums);
        if(nums==1)sum+=min(m4[num],x-y);
        else sum+=min(m3[num],x-y);
        nums=num;
    }
    
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ns[i];
    cin>>k;
    for(int i=1;i<=k;i++)cin>>ks[i];
    obrabotim1();
    //Pechat();
    resh();
    cout<<sum<<endl;
    return 0;
}
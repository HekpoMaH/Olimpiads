#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define ll long long
using namespace std;

ll d[32][32],m;
int n;
string s;

ll go(int k1,int k2)
{
    if(d[k1][k2]!=m)return d[k1][k2];
    int i;
    ll res=0,tmp=0;
    for(i=k1;i<=k2;i++)
     if(s[i]=='*')res++;
     else if(s[i]=='-')tmp++;
    if((res==0&&tmp==0)||res==(k2-k1)/2)
    {
        res=(ll)((int)(s[k1]-'0'));
        for(i=k1+1;i<=k2;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                if(s[i-1]=='+')res=res+(ll)((int)(s[i]-'0'));
                else res=res*(ll)((int)(s[i]-'0'));
            }
        }
        d[k1][k2]=res;
        return res;
    }
    res=m;
    int j,g;
    for(i=k1;i<=k2;i++)
    {
        if(s[i]=='*')
        {
            for(j=k1;j<i;j+=2)
             for(g=i+1;g<=k2;g+=2)
             {
                    tmp=go(j,i-1)*go(i+1,g);
                    if(j>k1&&s[j-1]=='*')tmp*=go(k1,j-2);
                    if(g<k2&&s[g+1]=='*')tmp*=go(g+2,k2);
                    if(j>k1&&s[j-1]=='-')tmp=go(k1,j-2)-tmp;
                    if(g<k2&&s[g+1]=='-')tmp-=go(g+2,k2);
                    if(j>k1&&s[j-1]=='+')tmp+=go(k1,j-2);
                    if(g<k2&&s[g+1]=='+')tmp+=go(g+2,k2);
                    if(tmp<res)res=tmp;
             }
        }
        else if(s[i]=='-')
        {
            for(j=k1;j<i;j+=2)
             for(g=i+1;g<=k2;g+=2)
             {
                    tmp=go(j,i-1)-go(i+1,g);
                    if(j>k1&&s[j-1]=='*')tmp*=go(k1,j-2);
                    if(g<k2&&s[g+1]=='*')tmp*=go(g+2,k2);
                    if(j>k1&&s[j-1]=='-')tmp=go(k1,j-2)-tmp;
                    if(g<k2&&s[g+1]=='-')tmp-=go(g+2,k2);
                    if(j>k1&&s[j-1]=='+')tmp+=go(k1,j-2);
                    if(g<k2&&s[g+1]=='+')tmp+=go(g+2,k2);
                    if(tmp<res)res=tmp;
             }
        }
    }
    d[k1][k2]=res;
    return res;
}

int main()
{
    int i,j;
    cin>>s;
    n=s.size();
    m=1000000000000000001LL;
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     {
            if(i==j)d[i][j]=(ll)((int)(s[i]-'0'));
            else d[i][j]=m;
     }
    cout<<go(0,n-1)<<"\n";
}

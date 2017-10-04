#include<bits/stdc++.h>
using namespace std;
long long N;
void solve(long long n)
{
    long long beg;
    long long used[11],s,l,cf;
    if(n==90){cout<<12345678990LL<<endl;return;}
    if(n%10==0)
    {
        if(n%3==0)beg=12334000000LL;
        else beg=11234000000LL;
        for(int i=56789;i<=98765;i++)
        {
            memset(used,0,sizeof(used));
            s=i;
            int j;
            while(s>0)
            {
                j=s%10;
                if(j<5)break;
                if(used[j]>0)break;
                used[j]=1;
                s/=10;
            }
            if(s==0&&(beg+10*i)%n==0){cout<<beg+10*i<<endl;return;}
        }
    }
    if(n%9==0)
    {
        beg=10234000000LL;
        for(int i=567899;i<=998765;i++)
        {
            memset(used,0,sizeof(used));
            s=i;
            int j;
            while(s>0)
            {
                j=s%10;
                if(j<5)break;
                if((j<9&&used[j]>0)||used[j]>1)break;
                used[j]++;;
                s/=10;
            }
            if(s==0&&(beg+i)%n==0){cout<<beg+i<<endl;return;}
        }
    }
    if(n%3==0)beg=10233000000LL;
    else beg=10123000000LL;
    for(int i=456789;i<=987654;i++)
    {
        memset(used,0,sizeof(used));
        s=i;
        int j;
        while(s>0)
        {
            j=s%10;
            if(j<4)break;
            if(used[j]>0)break;
            used[j]=1;
            s/=10;
        }
        if(s==0&&(beg+i)%n==0){cout<<beg+i<<endl;return;}
    }
    cout<<"no"<<endl;
}
int main()
{
    cin>>N;
    solve(N);
    cin>>N;
    solve(N);
    return 0;
}

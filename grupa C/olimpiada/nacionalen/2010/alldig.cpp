#include<iostream>
#include<cstdio>
using namespace std;
void solve(long long int n)
{
    long long a,s,c;
    int f[10];
    if(n==90){a=12345678990LL;cout<<a<<endl;return;}
    if(n%10==0)
    {
        if(n%3==0)a=1233400000LL;
        else a=1123400000LL;
        for(int i=56789;i<=98765;i++)
        {
            for(int j=5;j<=9;j++)f[j]=0;
            s=i;
            while(s>0)
            {
                c=s%10;
                if(c<5)break;
                if(f[c]>0)break;
                f[c]=1;
                s/=10;
            }
            if(s==0&&(a+i)*10%n==0)
            {
                cout<<(a+i)*10<<endl;return;
            }
        }
    }
    if(n%9==0)
    {
        a=10234000000LL;
        for(int i=567899;i<=998765;i++)
        {
            for(int j=5;j<=9;j++)f[j]=0;
            s=i;
            while(s>0)
            {
                c=s%10;
                if(c<5)break;
                if((c<9&&f[c]>0)||f[c]>1)break;
                f[c]++;
                s/=10;
            }
            if(s==0&&(a+i)%n==0)
            {
                cout<<a+i<<endl;return;
            }
        }
    }
    if(n%3==0)a=10233000000LL;
    else a=10123000000LL;
    for(int i=456789;i<=987654;i++)
    {
        for(int j=4;j<=9;j++)f[j]=0;
        s=i;
        while(s>0)
        {
            c=s%10;
            if(c<4)break;
            if(f[c]>0)break;
            f[c]=1;
            s/=10;
        }
        if(s==0&&(a+i)%n==0)
        {
          cout<<a+i<<endl;return;
        }
    }
    cout<<"no"<<endl;
}
int main()
{
    long long n,l;
    cin>>n;
    solve(n);
    cin>>n;
    solve(n);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,s,sum,a,q;
vector<long long> monos;
void getgreedy(int x)
{
    //cout<<x<<endl;
    int x1=x;
    if(x==0)return;
    int mn=99;
    int br=0;
    while(x1!=0)
    {
        mn=min(x1%10,mn);
        br++;x1/=10;
    }
    //cout<<"mn="<<mn<<" "<<br<<endl;
    if(mn!=0)
    {
        long long amn=0;
        for(int i=1;i<=br;i++)amn*=10,amn+=mn;
        monos.push_back(amn);
        getgreedy(x-amn);//cout<<x<<" "<<mn<<" "<<br<<endl;
    }
    else
    {
        long long amn=0;
        for(int i=1;i<br;i++)amn*=10,amn+=9;
        monos.push_back(amn);
        getgreedy(x-amn);
    }
}
void sl4()
{

}
int main()
{
    cin>>n;
    getgreedy(n);
    for(int i=0;i<9;i++)
    {
        if((9*n+i)%10==0)
        {
            s=i;
        }
    }
    a=9*n+s;
    int a1=a;
    while(a1!=0)
    {
        sum+=a1%10;
        if(a1%10==0)q++;
        a1/=10;
    }
    if(sum==s)sl4();
    //for(int i=0;i<monos.size();i++)cout<<monos[i]<<" ";cout<<"\n";
}

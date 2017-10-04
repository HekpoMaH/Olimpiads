#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
long long x,num1,br;
int used[12],used3[12];
set<int> s;
void check(long long n,long long m)
{
    int nn=m;
    //cout<<nn<<endl;
    while(n!=0)
    {
        //cout<<"%"<<n%10<<endl;
        used[n%10]++;
        n/=10;
    }
    while(m!=0)
    {
        //cout<<"%m1 "<<m%10<<endl;
        used3[m%10]++;
        m/=10;
    }
    for(int i=0;i<=9;i++)
    {
        //cout<<i<<" "<<used[i]<<" "<<used3[i]<<endl;
        if(used[i]!=0&&used3[i]!=0){br++;return;}
    }
}
int main()
{
    cin>>x;
    for(int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            memset(used,0,sizeof(used));
            memset(used3,0,sizeof(used3));
            check(x,i);
            s.insert(i);
            memset(used,0,sizeof(used));
            memset(used3,0,sizeof(used3));
            if(s.find(x/i)==s.end())check(x,x/i),s.insert(x/i);
        }
    }
    cout<<br<<endl;
    return 0;
}

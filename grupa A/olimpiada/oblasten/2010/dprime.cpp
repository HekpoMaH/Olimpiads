#include<bits/stdc++.h>
using namespace std;
short v[2][900];
int br,a,b;
map<int,bool>ma;
inline void check(int x)
{
    if(x<a || x>b || ma.find(x)!=ma.end())return;
    ma[x]=1;
    int i;
    for(i=2;i*i<=x;i++)
        if(x%i==0)return;
    br++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,j,k,m=0,p1,p2=0;
    cin>>a>>b;
    for(i=1;i<27;i++)
    {
        p1=0;
        int basi1=1<<((i>>1)+(i&1));
        int basi2=(1<<((i>>1)+(i&1)+1));
        for(j=basi1;j<basi2;j++)
        {
           int kj=sqrt(j);
            for(k=2;k<=kj;k++)
                if(j%k==0)break;
            if(k==int(kj)+1)v[i&1][p1++]=j;
        }
            for(k=0;k<p2;k++)
        for(j=0;j<p1;j++)
            {
               int fp=v[(i+1)&1][k],sp=v[i&1][j];
               check((fp<<((i>>1)+(i%2))+1)+sp);
               check((sp<<((i>>1)+1))+fp);
            }
        swap(p1,p2);
    }
    cout<<br<<"\n";
}

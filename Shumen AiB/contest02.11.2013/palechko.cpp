#include<bits/stdc++.h>
using namespace std;
int w,h,k;
vector<pair<int,int> > hand[3];
void read()
{
    cin>>w>>h>>k;
    int fkc,hx,hy;
    for(int i=1;i<=k;i++)
    {
        cin>>fkc;

        for(int j=1;j<=fkc;j++)
        {
            cin>>hx>>hy;
            hand[i].push_back(make_pair(hx,hy));
        }
    }
    if(k==1)solve1();
    if(k==2)solve2();
}
int chekpos()
void solve1()
{
    int m;
    cin>>m;
    int mn=99999999;
    int on=chekpos(0);
    int tw=chekpos(w);
}
int main()
{
    read();
}

#include<iostream>
#include<string>
using namespace std;
string t,p;
int pkmp[128];
void prekmp()
{
    int sz,pos1=0,pos2=2;
    sz=p.size();
    while(pos2<=sz)
    {
        if(p[pos1]==p[pos2-1])
        {
            pkmp[pos2]=pos1+1;
            pos1++;pos2++;
        }
        else
        {
            if(pos1>0)pos1=pkmp[pos1];
            else pos2++;
        }
    }
}
void solve()
{
    int ans=0;
    int pos1=0,pos2=0;
    int sp=p.size(),st=t.size();
    while(pos1<st)
    {
        if(t[pos1]==p[pos2])
        {
            pos1++;
            pos2++;
        }
        else
        {
            if(pos2>0)pos2=pkmp[pos2];
            else pos1++;
        }
        if(pos2==sp)
        {
            ans++;
            pos2=pkmp[pos2];
        }
    }
    cout<<ans<<endl;
}
int main()
{
    cin>>t;
    cin>>p;
    prekmp();
    solve();
}
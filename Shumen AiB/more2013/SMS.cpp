#include<bits/stdc++.h>
using namespace std;
string start,last;
vector<string> v[3];
map<int,int> st[11];
map<int,pair<pair<int,int>,int> > mp[11];
string gtn()
{
    char a[16];
    scanf("%s",a);
    return (string)a;
}
void glon(vector<string>&v)
{
    v.erase(v.begin(),v.end());
    int sz;
    scanf ("%d",&sz);
    while(sz--)v.push_back ( gtn() );
}
void scan()
{
    start=gtn();last=gtn();
    glon(v[0]);
    for(int i=0;i<4;i++)
    {
        glon(v[i]);// vi, huh.. stand for Violence
    }
}
int commpref(string &t1,string &t2)
{
    for(int i=0;i<10;i++)
    {
        if(t1[i]!=t2[i])
        return i;
    }
}
void filtera4()
{
    for(int i=0;i<11;i++)
    st[i].erase(st[i].begin(),st[i].end());
    for(int i=0;i<v[2].size();i++)
    {
        int number=0,p4=commpref(v[2][i],last);
        //cout<<"p4="<<p4<<endl;
        for(int dig=0;dig<10;dig++)
        {
            st[dig][number]=max(p4,st[dig][number]);
            number=number*10+v[2][i][dig]-'0';
        }
    }
    //st[dig][number]- maximum prefix btw(up to [dig]th digit of number "number", scrudge's number)
}
void fillmap()
{
    for(int i=0;i<11;i++)mp[i].erase(mp[i].begin(),mp[i].end());
    for(int i=0;i<v[1].size();i++)
    {
        int number=0;
        pair<int,int> mxcm=make_pair(-1,-1);
        for(int dig=0;dig<10;dig++)
        {
            if(!st[dig].count(number))break;
            if(mxcm.first+mxcm.second<dig+st[dig][number])mxcm=make_pair(dig,st[dig][number]);
            number=number*10+v[1][i][dig]-'0';
        }
        //for each tel. number of the mid part we get max common
        if(mxcm==make_pair(-1,-1))continue;
        number=0;
        for(int dig=0;dig<10;dig++)
        {
            if(mp[dig][number].first.first+mp[dig][number].first.second<=mxcm.first+mxcm.second)
            {
                mp[dig][number]=make_pair(mxcm,i);

            }number=number*10+v[1][i][dig]-'0';
        }
    }
}
int findans(int mustprint)
{
    int res=-2;
    string a2;
    int idx3,com,p4;
    for(int i=0;i<v[0].size();i++)
    {
        int p1=commpref(start,v[0][i]);
        int number=0;
        for(int dig=0;dig<10;dig++)
        {
            map<int,pair<pair<int,int>,int> >::iterator it=mp[dig].find(number);
            if(it==mp[dig].end())break;
            int val=dig+it->second.first.first+it->second.first.second+p1;
            if(val>=res)
            {
                res=val;
                a2=v[0][i];
                idx3=it->second.second;
                com=it->second.first.first;
                p4=it->second.first.second;
            }
            number=number*10+v[0][i][dig]-'0';
        }
    }
    if(res==-2)while(1);
    if(mustprint)
    {
        cout<<start<<endl;
        cout<<a2<<endl;
        cout<<v[1][idx3]<<endl;
        for(int i=0;i<v[2].size();i++)
        {
            if(commpref(v[1][idx3],v[2][i])>=com&&commpref(v[2][i],last)>=p4)
            {
                cout<<v[2][i]<<endl;
                break;
            }
        }
        cout<<last<<endl;
    }
    return res;
}
int used[64];
int go(int mustprint)
{
    filtera4();
    fillmap();
    return findans(mustprint);
}
void solve()
{
    printf("%d 5\n",40-go(0));
    go(1);
}
int main()
{
    scan();
    solve();
}

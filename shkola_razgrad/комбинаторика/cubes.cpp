#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct bx
{
    int upp,downn,leftt,rightt,backk,frontt;
};

bx f1,f2;

map <bx, int> m;
map <bx, int>::iterator it;
void dfs(bx f)
{
    if(m[f]!=1)return;
    //m[f]=1;
    //bx n;
    /*n.upp=f.frontt;
    n.downn=f.backk;
    n.leftt=f.leftt;
    n.rightt=f.rightt;
    n.backk=f.upp;
    n.frontt=f.downn;*/
    //dfs(n);
    /*n.upp=f.backk;
    n.downn=f.frontt;
    n.leftt=f.leftt;
    n.rightt=f.rightt;
    n.backk=f.downn;
    n.frontt=f.upp;*/
    //dfs(n);
    /*n.upp=f.rightt;
    n.downn=f.leftt;
    n.leftt=f.upp;
    n.rightt=f.downn;
    n.backk=f.backk;
    n.frontt=f.frontt;*/
    //dfs(n);
    /*n.upp=f.leftt;
    n.downn=f.rightt;
    n.leftt=f.downn;
    n.rightt=f.upp;
    n.backk=f.backk;
    n.frontt=f.frontt;*/
    //dfs(n);
}
int main()
{
    cin>>f1.upp>>f1.downn>>f1.leftt>>f1.rightt>>f1.frontt>>f1.backk;
    cin>>f2.upp>>f2.downn>>f2.leftt>>f2.rightt>>f2.frontt>>f2.backk;
    dfs(f1);
    it=m.find(f2);
    if(it!=m.end())cout<<"Yes"<<endl;
    //else cout<<"No"<<endl;
    return 0;
}
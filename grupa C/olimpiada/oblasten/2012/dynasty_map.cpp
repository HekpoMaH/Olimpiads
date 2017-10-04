#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int m;
map<string,string> p;
map<string,string>::iterator it;
vector<pair<int,string> > v;
string father,son;
void check(string x)
{
    int c=0;   
    while(p.count(x)>0){x=p[x];c++;}
    v.push_back(pair<int,string>(c,x));
}
int main()
{
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>father>>son;
        if(p.count(son)>0&&p[son]!=father){cout<<son<<endl;return 0;}
        p[son]=father;
    }
    for(it=p.begin();it!=p.end();it++)check((*it).first);
    cout<<(*max_element(v.begin(),v.end())).second<<endl;
    return 0;
}

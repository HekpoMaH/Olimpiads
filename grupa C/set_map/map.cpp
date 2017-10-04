#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
map<string, int> m;
map<string, int>::iterator it;
int main()
{
    m["az"]=1;
    m["ti"]=2;
    m["toi"]=3;
    //cout<<m["ti"]<<endl;
    vector<pair<string,int> >v(m.begin(),m.end());
    it=m.find("toi");
    cout<<(*it).first<<" "<<(*it).second<<endl;
    for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;
    return 0;
}
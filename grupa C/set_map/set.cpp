#include<iostream>
#include<set>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
set<int> s;
set<int>::iterator it;
int main()
{
    s.insert(11);s.insert(1);s.insert(43);
    //s.erase(11);
    if(s.find(11)!=s.end())cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    for(it=s.begin();it!=s.end();it++)cout<<*it<<endl;
    return 0;
}
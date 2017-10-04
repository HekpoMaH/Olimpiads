#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int m;
map<string,string> p;
map<string,string>::iterator it;
vector<pair<int,string> > v;

void up(string b)
{
  int c=0;   
  while(p.count(b)>0) {b=p[b]; c++;}
  v.push_back(pair<int,string>(c,b));
}

int main()
{
 cin >> m;
 for(int i=1;i<=m;i++) 
  {
    string a,b;
    cin >> a >> b;
    if(p.count(b)>0) if(p[b] != a) {cout << b << endl; return 0;}
    p[b]=a;
  }
 for(it=p.begin();it!=p.end();it++) up((*it).first);
 cout << (*max_element(v.begin(),v.end())).second << endl;
}

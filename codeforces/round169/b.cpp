#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
string s;
set<char> c;
long long used[100],mx,mi,mx2,mi2;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        c.insert(s[i]);
        used[s[i]-'a']++;//if(used[s[i]-'a']>mx){mx=used[s[i]-'a'];mi=s[i]-'a';}
    }
    for(int i=0;i<100;i++)
    {
        if(used[i]%2==1)mx++;
    }
    if(mx!=0)mx--;

    if(mx%2==0)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}


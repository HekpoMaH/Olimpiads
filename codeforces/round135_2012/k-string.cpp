#include<iostream>
#include<string>
using namespace std;
string s;
int a[44],k,br=0;
pair<char, int> p[1004];
int main()
{
    cin>>k;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        a[s[i]-'a']++;
    }
    //cout<<(int)('z'-'a'+1);
    for(int i=0;i<26;i++)
    {
        if(a[i]%k!=0)
        {
            cout<<-1<<endl;return 0;
        }
        else
        {
            br++;
            p[br].first=(char)('a'+i);
            p[br].second=a[i]/k;
        }
    }
    for(int v=1;v<=k;v++)for(int i=1;i<=br;i++)
    {
        for(int j=1;j<=p[i].second;j++)cout<<p[i].first;
    }
    cout<<endl;
    return 0;
}
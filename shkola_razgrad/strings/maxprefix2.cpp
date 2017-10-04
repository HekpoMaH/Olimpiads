#include<iostream>
#include<string>
using namespace std;
string s;
int m;
int a,b;
void solve(int a,int b)
{
    string s1=s.substr(a),s2=s.substr(b);
    int br=0;
    for(int i=0;i<min((int)s1.size(),(int)s2.size());i++)
    {
        if(s1[i]!=s2[i])break;
        br++;
    }
    cout<<br<<endl;
}
int main()
{
    cin>>s;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        solve(a,b);
    }
    return 0;
}
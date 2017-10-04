#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
int br,used[100],mn=0;
string s,t,ans;
bool co(string s1,string s2)
{
    for(int i=0;i<s1.size();i++)
    {
        if(s1<s2)return true;
        if(s1>s2)return false;
    }
    return false;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    cin>>s;cin>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    cout<<s<<" "<<t<<endl;
    for(int i=0;i<t.size();i++)if(s[i]!=t[i])mn++;
    cout<<mn<<endl;
}


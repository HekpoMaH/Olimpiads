#include<bits/stdc++.h>
using namespace std;
string s;
vector<string> code;
int n;
void gennext()
{
    vector<string> ncode;
    ncode=code;
    for(int i=0;i<ncode.size();i++)
    {
        ncode[i]="0"+ncode[i];
    }
    for(int i=code.size()-1;i>=0;i--)
    {
        ncode.push_back(code[i]);
        ncode[ncode.size()-1]="1"+ncode[ncode.size()-1];
    }
    code=ncode;
}
int main()
{
    cin>>n;
    code.push_back("0");code.push_back("1");
    for(int i=2;i<=n;i++)gennext();
    for(int i=0;i<code.size();i++)cout<<code[i]<<" ";
    cout<<endl;
}

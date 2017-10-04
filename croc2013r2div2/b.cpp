#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
string s;
int br=0,mbr;
int main()
{
    int n,k;
    cin>>n>>k;
    cin>>s;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='#')br++;
        if(s[i]=='.')
        {
            mbr=max(mbr,br);
            br=0;
        }
    }
    if(mbr>=k)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

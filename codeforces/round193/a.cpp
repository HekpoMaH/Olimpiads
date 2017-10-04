#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,br=0;
    cin>>n;
    string s;
    cin>>s;
    //cout<<s<<endl;
    for(int i=0;i<s.size();i+=n)
    {
        //cout<<s[i-1]<<" "<<s[i-2]<<" "<<s[i-3]<<" "<<i<<endl;
        if(i>=4&&s[i-1]==s[i-2]&&s[i-2]==s[i-3])br++;
    }
    cout<<br<<endl;
}

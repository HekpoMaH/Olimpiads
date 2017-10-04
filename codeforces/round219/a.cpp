#include<bits/stdc++.h>
using namespace std;
string s;
int k,cnt[100];
int main()
{
    cin>>k;
    for(int i=1;i<=4;i++)
    {
        cin>>s;
        for(int j=0;j<4;j++)if(s[j]!='.'){cnt[s[j]-'0']++;}
    }
    //cout<<cnt[2]<<endl;
    for(int i=1;i<=9;i++)if(cnt[i]>2*k){cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;
}

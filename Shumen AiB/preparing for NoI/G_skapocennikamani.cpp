#include<iostream>
#include<cstring>
using namespace std;
string s;
long long used[63],aans;
long long n,k;
void solvefor(string st)
{
    long long ans=0;
    memset(used,0,sizeof(used));
    for(int i=0;i<n;i++)used[s[i]-'a']++;
    if(st[0]==st[1])
    {
        for(int i=1;i<used[st[0]-'a'];i++)
        {
            ans+=i;
        }
        aans+=ans;
        //cout<<ans<<endl;
        return ;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]==st[0])
            {
                ans+=used[st[1]-'a'];
            }
            if(s[i]==st[1])used[st[1]-'a']--;
        }
        aans+=ans;
        //cout<<ans<<endl;
    }
}
int main()
{
     cin>>n>>k;
     cin>>s;

     for(int i=1;i<=k;i++)
     {
         string ss;cin>>ss;
         solvefor(ss);
     }
     cout<<aans<<endl;
}

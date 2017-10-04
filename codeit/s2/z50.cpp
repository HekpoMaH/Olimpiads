#include<bits/stdc++.h>
using namespace std;
int n,k,cnt[299];
string s,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream fin("letters.in");
    ofstream fout("letters.out");
    fin>>n>>k;
    fin>>s;
    int sz=s.size();
    for(int i=0;i<sz;i++)
    {
        cnt[s[i]-'a'+1]++;
    }
    for(int i=1;i<=26;i++)
    {
        if(cnt[i]>0)
        {
            ans+=(char)('a'+i-1);
            cnt[i]--;
            if(ans.size()==k)
            {
                break;
            }
        }
    }
    while(ans.size()<k)
    {
        for(int i=1;i<=26;i++)
        {
            for(int j=1;j<=cnt[i];j++)
            {
                ans+=(char)('a'+i-1);
                if(ans.size()==k)
                {
                    break;
                }
            }
            if(ans.size()==k)
            {
                break;
            }
        }
    }
    sort(ans.begin(),ans.end());
    fout<<ans<<endl;
}

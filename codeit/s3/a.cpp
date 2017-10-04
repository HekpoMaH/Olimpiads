#include<bits/stdc++.h>
using namespace std;
const int maxn=1009;
int used[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream fin("anagrams.in");
    ofstream fout("anagrams.out");
    int n;
    fin>>n;
    string s[maxn];
    for(int i=1;i<=n;i++)
    {
        fin>>s[i];
        sort(s[i].begin(),s[i].end());
    }
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i+1])
        {
            fout<<-1<<"\n";
            return 0;
        }
    }
    fout<<s[n]<<"\n";
    return 0;
}

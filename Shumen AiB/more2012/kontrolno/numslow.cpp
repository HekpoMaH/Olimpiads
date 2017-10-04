#include<iostream>
#include<set>
#include<string>
using namespace std;
set<long long> ans;
string num;
int used[12],nn;
void solve(int x)
{
    for(int i=0;i<=9;i++)
    {
        if(used[i]!=0)
        {
            used[i]--;
            nn=x*10+i;
            ans.insert(nn);
            solve(nn);
            used[i]++;
        }
    }
}
int main()
{
    cin>>num;
    for(int i=0;i<num.size();i++)
    {
        used[num[i]-'0']++;
    }
    solve(0);
    cout<<ans.size()<<endl;
    return 0;
}
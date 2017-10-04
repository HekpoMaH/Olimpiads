#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
vector<int> workingnum[19];
int n;
int br;
string ans;
int all;
string given,x4e,help;
queue<string> q;
vector<string>fans;
string numb[11]={"1111110","0110000","1101101","1111001","0110011","1011011","1011111","1110000","1111111","1111011"};
int k;
int dainum(string na)
{
    for(int i=0;i<10;i++)
    {
        if(na==numb[i])return i;
    }
    return -1;
}
bool ispossible(string inp,int i)
{
    for(int j=0;j<inp.size();j++)
    {
        if(inp[j]=='1'&&numb[i][j]=='0')return false;
    }
    return true;
}
void solve(int pos)
{
    if(pos==n){fans.push_back(ans);}
    else
    {
        for(int i=0;i<workingnum[pos].size();i++)
        {
            //cout<<pos<<" "<<i<<" "<<workingnum[pos][i]<<endl;
            ans+=workingnum[pos][i]+'0';//cout<<"W"<<endl;
            solve(pos+1);
            if(pos+1>=2)ans.erase(pos,1);
            else ans="";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>given;
        for(int j=0;j<10;j++)
        {
            if(ispossible(given,j)==true)
            {
                workingnum[i].push_back(j);
            }
        }
    }
    //for(int i=0;i<workingnum[0].size();i++)cout<<workingnum[0][i]<<endl;
    //cout<<all-n<<endl;
    solve(0);
    cout<<fans.size()<<endl;
    for(int i=0;i<fans.size();i++)cout<<fans[i]<<endl;
    //for(int i=0;i<k;i++)cout<<ans[i]<<endl;
}
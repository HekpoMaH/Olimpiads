#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
vector<int> b[100],g[100],ans,c;
int n,used[100];
void batrak(int x)
{
    if(x==n+1)
    {
        if(c.size()>ans.size())
        {
            ans=c;
        }return;
    }
    if(c.size()+(n-x+3)/3+3<ans.size())return;
    batrak(x+1);
    if(!used[x])
    {
        b[x].clear();
        g[x].clear();
        for(int i=c.size()-1;i>=0;i--)
        {
            if(x+2*(x-c[i])>n)break;
            if(x+2*(x-c[i])<=n)b[x].push_back((x+2*(x-c[i]))),g[x].push_back(0);
        }
        for(int i=0;i<b[x].size();i++)
        {
            if(used[b[x][i]]==1)g[x][i]=1;
            else used[b[x][i]]=1;
        }
        c.push_back(x);
        batrak(x+1);
        c.pop_back();
        for(int i=0;i<b[x].size();i++)if(g[x][i]==0)used[b[x][i]]=0;
    }
}
int main()
{

    ofstream fout("fukvalkae.out");//b.reserve(100),c.reserve(100);
    for (n = 1; n <= 70; n++) {
    ans.clear();
    batrak(1);
    cout<<n<<endl;
    fout<<"if(n=="<<n<<"){fout<<";fout<<ans.size()<<"\\n";
    for (int i = 0; i < ans.size(); i++)
        fout << ans[i] << " ";fout<<"<<endl;}";
    fout << endl << endl;}
}

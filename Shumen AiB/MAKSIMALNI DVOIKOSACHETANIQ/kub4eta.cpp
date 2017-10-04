#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
vector<int> v[1002];
int s[1002],used[1002],n,m;
string name;
string kub;
bool dfs(int node)
{
    //cout<<node<<" "<<s[node]<<endl;
    if(s[node]==0)return true;
    used[node]=1;int p;
    if(s[node]!=0&&used[s[node]]==0)
    {
        p=dfs(s[node]);
        //used[node]=0;
        return p;
    }
    for(int i=0;i<v[node].size();i++)
    {
        if(used[v[node][i]]==0)
        {
            p=dfs(v[node][i]);
            if(p==1){s[node]=v[node][i],s[v[node][i]]=node;//cout<<v[node][i]<<" "<<s[node]<<" "<<node<<endl;
            //used[node]=0;
            return p;}
        }
    }
    //used[node]=0;
    return 0;
}
void read()
{
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>name;
    int p;
    for(int i=1;i<=n;i++)
    {
        cin>>kub;
        for(int j=0;j<6;j++)
        {
            int l=0;
            for(int k=0;k<name.size();k++)
            {
                if(kub[j]==name[k]){v[i].push_back(n+k+1),v[n+k+1].push_back(i);}
            }
        }
    }
}
int main()
{
     read();
     int br=0;
     for(int i=1;i<=n;i++)
     {

             s[i]=i;
             if(dfs(i)==true)br++;
             else s[i]=0;
         memset(used,0,sizeof(used));
         /*for(j=1;j<=n+m;j++)
         cout<<s[j]<<" ";
         cout<<endl;
         for(j=1;j<=n+m;j++)
         cout<<used[j]<<" ";
         cout<<endl;*/
     }
     if(br<name.size()){cout<<"NO"<<endl;return 0;}
     cout<<"YES"<<endl;
     for(int i=n+1;i<=n+name.size();i++)cout<<s[i]<<" ";
     cout<<endl;
     //cout<<br<<endl;
}


#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int n,m,br,l,br2,br3;
int a[100][100];
vector<int> p;
vector<int> v[100];
string s;
void go(int node,int pred)
{
    //cout<<p.size()<<endl;
    for(int i=1;i<=n;i++)
    {
        if(a[node][i]>0)
        {
            a[node][i]--;a[i][node]--;p.push_back(i);br2++;go(i,node);p.pop_back();br2--;a[node][i]++;a[i][node]++;
        }
    }
    if(node==1&&pred!=-1)
    {
        if(br2==br3)
        {
            br++;
            //cout<<"AAA"<<endl;
            cout<<"Route "<<br<<": 0 ";
            for(int i=0;i<p.size();i++)cout<<p[i]-1<<" ";
            cout<<endl;
        }
        //cout<<br2<<" "<<br3<<endl;
    }
    //p.push_back(node);
}
int main()
{
    ios::sync_with_stdio(false);//cout<<"Number of routes: 0"<<endl;
    cin>>n;
    //for(int i=1;i<=n;i++)p.push_back(i);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=n;j++){a[i][j]=s[j-1]-'0';if(a[i][j]==1)br3++;}
    }br3/=2;
    go(1,-1);
    cout<<"Number of routes: "<<br<<endl;
}


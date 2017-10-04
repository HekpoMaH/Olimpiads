#include<iostream>
#include<string>
using namespace std;
string s;
string tup[100];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tup[i];
    }
    cin>>s;
    string ans="";
    int x,y,z,zz[9],br;
    for(int i=1;i<=n;i++)
    {
        x=0;y=0;
        for(int j=5;j>=0;j--)
        {
            z=(int)tup[i][j];
            br=0;
            while(z!=0)zz[br++]=z%2,z/=2;
            
            if(zz[j]==1)x*=2,x+=1;
            else x*=2;
            if(zz[(j+3)%6]==1)y*=2,y+=1;
            else y*=2;
        }
        ans+=s[x];ans+=s[y];
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
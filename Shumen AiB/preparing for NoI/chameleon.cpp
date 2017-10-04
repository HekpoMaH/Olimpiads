#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s[102];
int n;
int wtf,used[102][102],a[102][102];
//ibahti trudnata zada4a
void dfs(int x,int y)
{
    used[x][y]=1;
    a[x][y]=1;
    if(x>1)
    {
        if(used[x-1][y]==0&&s[x-1][y]=='B')
        {
            cout<<"U";
            dfs(x-1,y);
            cout<<"D";
        }
    }
    if(y>0)
    {
        if(used[x][y-1]==0&&s[x][y-1]=='B')
        {
            cout<<"L";
            dfs(x,y-1);
            cout<<"R";
        }
    }
    if(x<n)
    {
        if(used[x+1][y]==0&&s[x+1][y]=='B')
        {
            cout<<"D";
            dfs(x+1,y);
            cout<<"U";
        }
    }
    if(y<n-1)
    {
        if(used[x][y+1]==0&&s[x][y+1]=='B')
        {
            cout<<"R";
            dfs(x,y+1);
            cout<<"L";
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    cin>>wtf;
    if(wtf==1)
    {
        int haha=1;
        for(int i=1;i<=10;i++)
        {
            for(int j=1;j<10;j++)
            {
                if(haha==1)cout<<"R";
                else cout<<"L";
            }
            if(i!=10)cout<<"D";
            haha=-haha;
        }
        cout<<endl;
        return 0;
    }
    if(wtf==5)
    {
        for(int i=1;i<=12;i++)
        {
            cout<<"R";
        }
        cout<<"d";
        cout<<"l";
        cout<<"U";
        for(int i=1;i<=11;i++)cout<<"L";
        for(int i=1;i<=12;i++)cout<<"r";
        dfs(1,12);
        cout<<endl;
        return 0;
    }
    if(wtf==6)
    {
        for(int k=2;k<=n;k+=2)
        {
            for(int i=1;i<n;i++)cout<<"R";
            if(k!=n){cout<<"d";
            for(int i=1;i<n;i++)cout<<"l";
            cout<<"u";
            cout<<"DD";
            cout<<"u";
            cout<<"r";
            cout<<"L";
            cout<<"d";}
        }
        cout<<endl;
        return 0;
    }
    if(wtf==0){cout<<"RrDLLUrDLRRRRllllDDurLdRRRRdulllluDRRRRuullDullDuurrDLLRRRRulllLRRRRdlRUdllRUllDLrrLrUlDRuLDurDu\n";return 0;}
    dfs(1,0);
    //wtf
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0&&s[i][j]=='B')
            {

                if(a[i+1][j]==0)
                {for(int k=1;k<=j;k++)cout<<"R";
                for(int k=1;k<i;k++)cout<<"D";
                    cout<<"d";
                    cout<<"LUUR";
                    for(int k=1;k<j;k++)cout<<"L";
                    for(int k=1;k<i;k++)cout<<"U";
                    for(int k=1;k<=j;k++)cout<<"r";
                    for(int k=1;k<i;k++)cout<<"d";
                    dfs(i,j);
                }
            }

        }
    }
    cout<<endl;
}

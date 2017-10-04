#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
string s[1009];int ii=1;
int n,m,al,sum,br,letter,idx,idx2=1;
int used[1009][1009];
void go(int x,int y)
{
    if(br==ii)return;
    br++;
    used[x][y]=1;
    cout<<x<<" "<<y<<" "<<br<<" "<<ii<<endl;
    if(br==ii&&al>=ii)return;
    s[x][y]=(char)('A'+letter);
    if(x-1>=0&&used[x-1][y]==0&&(br<ii||al<ii))go(x-1,y);
    if(br==ii&&al>=ii)return;
    if(x+1<n&&used[x+1][y]==0&&(br<ii||al<ii))go(x+1,y);
    if(br==ii&&al>=ii)return;
    if(y-1>=0&&used[x][y-1]==0&&(br<ii||al<ii))go(x,y-1);
    if(br==ii&&al>=ii)return;
    if(y+1<m&&used[x][y+1]==0&&(br<ii||al<ii))go(x,y+1);
    if(br==ii&&al>=ii)return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;al=n*m;

    while(ii<=al)
    {
        sum+=ii;al-=ii;br=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(used[i][j]==0){cout<<"Start "<<i<<" "<<j<<" "<<ii<<" "<<letter<<endl;go(i,j);br=0;break;break;break;cout<<"wta"<<endl;}
            }
        }
        cout<<"over loop"<<endl;
        ii++;letter++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<s[i][j];
        }
        cout<<endl;
    }

}


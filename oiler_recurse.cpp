#include<iostream>
//#include<vector>
using namespace std;
int g[100][100];
int n,m,x,y;
void walk(int pos)
{
    for(int i=1;i<=n;i++)
    {
        if(g[pos][i]>0)
        {
            g[pos][i]--;g[i][pos]--;
            walk(i);
            break;
        }
    }
    cout<<pos<<endl;
}
int main/*a*/()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        g[x][y]++;g[y][x]++;
    }
    walk(1);
    return 0;
}
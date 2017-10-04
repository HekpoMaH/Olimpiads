#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
string s;
int r,c,a[100][100],br;
int main()
{
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='S')a[i][j]=1;
        }
    }
    for(int i=1;i<=r;i++)
    {
        int l=0;
        for(int j=1;j<=c;j++)if(a[i][j]==1)l=1;
        if(l==0)for(int j=1;j<=c;j++)a[i][j]=2;
    }
    for(int i=1;i<=c;i++)
    {
        int l=0;
        for(int j=1;j<=r;j++)if(a[j][i]==1)l=1;
        if(l==0)for(int j=1;j<=r;j++)a[j][i]=2;
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(a[i][j]==2)br++;
        }
    }
    cout<<br<<endl;
}

#include<iostream>
using namespace std;
int n;
int x[100005],y[100005],used[2000][2000];
int br,mbr;
int main()
{
    br=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        used[x[i]][y[i]]++;
    }
    for(int i=0;i<=1999;i++)
    {
        for(int j=0;j<=1999;j++)
        {
            if(used[i][j]>mbr)mbr=used[i][j];
        }
    }
    cout<<mbr<<endl;
    return 0;
}

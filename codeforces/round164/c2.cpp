#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct po
{
    int x;
    int y;
};
vector<po>v[10000];
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    cout<<min(n,m)+1<<endl;
    for(i=n,j=0;i>=0 && j<=m;i--,j++)
    cout<<i<<" "<<j<<endl;
}
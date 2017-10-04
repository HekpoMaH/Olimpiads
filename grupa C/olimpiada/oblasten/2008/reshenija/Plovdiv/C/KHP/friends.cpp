#include<iostream>
#include<vector>
using namespace std;
vector<int>a[2006];
int abr[2006],o[2006];
bool used[2006];
int main()
{
    long max=0,m,i,j,x,y,b=1,e=1;
    int n;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        abr[x]++;
        abr[y]++;
    }
    o[0]=o[1]=used[1]=1;
    while(b<=e)
    {
        if(e-b+1>max)max=e-b+1;
        for(i=b;i<=e;i++)
        {
            for(j=0;j<abr[o[i]];j++)
            if(!used[a[o[i]][j]])
            {
                used[a[o[i]][j]]=1;
                o[0]++;
                o[o[0]]=a[o[i]][j];
            }
        }
        b=e+1;
        e=o[0];
        if(e-b+1>max)max=e-b+1;
    }
    cout<<max<<endl;
}

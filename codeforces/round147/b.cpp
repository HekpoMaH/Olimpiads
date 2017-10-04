#include<iostream>
#include<algorithm>
using namespace std;
struct st
{
    int x,y;
};
st num[3005];
int n,c[66],a[66][66],br,s,ans[3004][5],x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i],s+=c[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c[i];j++)
        {
            cin>>a[i][j];
            num[a[i][j]].x=i;num[a[i][j]].y=j;
        }
    }
    br=1;int fl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c[i];j++)
        {
            if(a[i][j]==br)
            {
                br++;continue;
            }
            fl=0;
            for(int i1=1;i1<=n;i1++)
            {
                for(int j1=1;j1<=c[i1];j1++)
                {
                    if(a[i1][j1]==br)
                    {
                        swap(a[i1][j1],a[i][j]);
                        x++;ans[x][1]=i;ans[x][2]=j;ans[x][3]=i1;ans[x][4]=j1;
                        br++;fl=1;break;
                    }
                }
                if(fl==1)break;
            }
        }
    }
    cout<<x<<endl;
    for(int i=1;i<=x;i++)cout<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<" "<<ans[i][4]<<endl;
    return 0;
}

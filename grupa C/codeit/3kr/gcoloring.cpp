#include<iostream>
using namespace std;
struct vertex
{
    int usedc[405];
    //int number;
    int izl;
};
struct edge
{
    int first,second;
};
int n,m,tab[304][304],mx,color[304][304],fc;
edge a[305];
vertex x[305];
int findcol(vertex &a,vertex &b)
{
    cout<<mx<<endl;
    for(int i=1;i<=mx;i++)
    {
        cout<<"us1="<<a.usedc[i]<<" "<<"us2="<<b.usedc[i]<<endl;
        if(a.usedc[i]==0&&b.usedc[i]==0){a.usedc[i]=1;b.usedc[i]=1;return i;}
    }
    return -1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].first>>a[i].second;
        //a[i].number=i;
        tab[a[i].first][a[i].second]=1;
        tab[a[i].second][a[i].first]=1;
        x[a[i].first].izl++;if(x[a[i].first].izl>mx)mx=x[a[i].first].izl;
        x[a[i].second].izl++;if(x[a[i].second].izl>mx)mx=x[a[i].second].izl;
    }
    cout<<mx<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(tab[i][j]==1&&color[i][j]==0)
            {
                cout<<"color->"<<i<<" "<<j<<" ";
                fc=findcol(x[i],x[j]);
                if(fc==-1){fc=mx+1;mx++;}
                color[i][j]=fc;
                color[j][i]=fc;
                cout<<fc<<endl;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(color[a[i].first][a[i].second]!=0)cout<<color[a[i].first][a[i].second]<<endl;
    }
    return 0;
}
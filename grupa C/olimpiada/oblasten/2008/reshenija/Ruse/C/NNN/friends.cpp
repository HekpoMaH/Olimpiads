#include <iostream>
int a[2001][2001],b[2001][2001],n,p;
long long i,j,k,m;
void teams(int p)
{
     int i1,j1,k1,p1;
     for (i1=1;i1<=b[p][0];i1++)
         for (j1=1;j1<=n;j1++)
             if (a[b[p][i1]][j1]==1) 
             {p1=1;for (k1=1;k1<=b[p+1][0];k1++) if (b[p+1][k1]==j1) {p1=0;break;}if (p1==1){ b[p+1][0]++;b[p+1][b[p+1][0]]=j1;
             a[b[p][i1]][j1]=0;a[j1][b[p][i1]]=0;}}
return;
}
bool donee()
{
     for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
             if (a[i][j]==1) return 0;
return 1;
}

using namespace std;
int main()
{
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        a[i][j]=0;

    for (i=1;i<=m;i++)
    {cin>>j>>k;
    a[j][k]=a[k][j]=1;}            
    b[1][0]=1;
    b[1][1]=1;
    k=1;
    do
    {
    teams(k);
    k++;
    }
    while (donee()==0);
    int max=1;
    for (i=2;i<=k;i++)
    if (b[i][0]>max) max=b[i][0];
    cout<<max<<endl<<endl;
    //for (i=1;i<=k;i++){
    //    for (j=1;j<=b[i][b[i][0]];j++) cout<<b[i][j]<<' ';cout<<endl;}
return 0;
}

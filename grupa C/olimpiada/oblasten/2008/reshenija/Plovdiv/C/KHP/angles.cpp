#include<iostream>
#include<vector>
using namespace std;
long minimum(long x,long y)
{
    if(x<y)return x;
    return y;
}
struct data
{
    int chislo,red,kolona;  
};
int main()
{
    vector<data>a[1006];
    long n,k,i,j,ygyl,max=-10000000,w,q;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
    a[i].reserve(n+6);
    for(j=1;j<=n;j++)
    cin>>a[i][j].chislo;
    }
    a[n+1].reserve(n+6);
    for(i=1;i<=n;i++)
    {
    a[n+1][i].kolona=0;
    a[n+1][i].red=0;
    a[i][n+1].kolona=0;
    a[i][n+1].red=0;
    for(j=n;j>=1;j--)
    {
        a[i][j].red=a[i][j+1].red+a[i][j].chislo;
        a[j][i].kolona=a[j+1][i].kolona+a[j][i].chislo;
    }
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        ygyl=a[i][j].chislo+a[i][j+1].red-a[i][minimum(j+k,n)+1].red+a[i+1][j].kolona-a[minimum(i+k,n)+1][j].kolona;
        if(ygyl>max)
        {
            max=ygyl;
            w=i;
            q=j;
        }
    }
    cout<<w<<' '<<q<<endl;
}

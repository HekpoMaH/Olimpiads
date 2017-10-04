#include<iostream>
#include<algorithm>
using namespace std;
int a[101][101];
int sorted[10001],real[10001];
int n,p,m,nb;
void input()
{
    cin>>n>>p;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}
void naprednomeren()
{
    int br=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            sorted[br]=a[j][i-j];br++;
        }
    }
    for(int i=n;i<2*n-1;i++)
    {
        for(int j=i-n+1;j<n;j++)
        {
            sorted[br]=a[j][i-j];br++;
        }
    }
}
void copyr()
{
    for(int i=0;i<nb;i++)
    {
        real[i]=sorted[i];
    }
}
int main()
{
    input();
    naprednomeren();
    nb=n*n;
    copyr();
    sort(sorted,sorted+nb);
    m=nb*p/100;
    int ans;
    int k=sorted[m-1];
    for(int i=0;i<nb;i++)if(real[i]>=k)ans=i+1;
    cout<<ans<<endl;
    return 0;
}
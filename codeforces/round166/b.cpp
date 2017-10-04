#include<iostream>
#include<vector>
using namespace std;
int n,m;
int a[555][555];
vector<int> r[555],c[555];
vector<int> sieve;
int erat[1000005];
void ms()
{
    for(int i=2;i<=1000000;i++)erat[i]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(erat[i]==1){for(int j=i+i;j<=1000000;j+=i)erat[j]=0;sieve.push_back(i);}
    }
}
int findn(int w)
{
    int l=0,r=sieve.size()-1;
    int an,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(sieve[mid]>w){an=sieve[mid];r=mid-1;}
        else l=mid+1;
    }
    return an;
}
long long mn=(long long)(555*555*100000+4);
int main()
{
    ms();
    ios::sync_with_stdio(false);
    //cout<<erat[1]<<" "<<erat[2]<<" "<<erat[3]<<" "<<erat[4]<<" "<<erat[5]<<" "<<erat[6]<<endl;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(erat[a[i][j]]==0)r[i].push_back(a[i][j]),c[j].push_back(a[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        long long br=0;
        for(int j=0;j<r[i].size();j++)
        {
            int x=findn(r[i][j]);
            br+=x-r[i][j];
        }
        //cout<<i<<" "<<br<<endl;
        mn=min(mn,br);
    }
    for(int i=1;i<=m;i++)
    {
        long long br=0;
        for(int j=0;j<c[i].size();j++)
        {
            int x=findn(c[i][j]);
            br+=x-c[i][j];
        }
        mn=min(mn,br);
    }
    cout<<mn<<endl;

}

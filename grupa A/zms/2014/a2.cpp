#include<iostream>
#include<vector>
using namespace std;
bool used[500001];
vector<long long>v[11];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,k,s=0,a,j,i;
    cin>>n>>k;
    if((n*(n+1)/2)%k!=0 || n<=k)
    {
        cout<<"NO\n";
        return 0;
    }
    a=(n*(n+1)/2)/k;
    for(i=0;i<k;i++)
    {
        for(j=n;j;j--)
            if(s+j<=a && !used[j])
            {
                s+=j;
                v[i].push_back(j);
                used[j]=1;
            }
        s=0;
    }
    for(i=0;i<k;i++)
    {
        n=v[i].size();
        cout<<n<<"\n";
        for(j=0;j<n-1;j++)
            cout<<v[i][j]<<" ";
        cout<<v[i][j]<<'\n';
    }
}

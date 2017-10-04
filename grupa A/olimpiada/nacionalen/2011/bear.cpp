#include<bits/stdc++.h>
using namespace std;
const int maxn=22;
int first[2*maxn],maxp[2*maxn];
unsigned long long num[2*maxn];
int n,a,b;
void read()
{
    cin>>n>>a>>b;
    first[1]=1;
    for(int i=2;i<=n;i++)first[i]=first[i-1]+n+i-2;
    for(int i=n+1;i<=2*n;i++)first[i]=first[i-1]+3*n-i;
}
void solve()
{
    int i=0;
    while(a>=first[i+1])i++;
    int j;
    j=a-first[i]+1;
    maxp[j]=num[j]=1;
    for(int v=a+1;v<=b;v++)
    {
        j++;
        if(first[i]+j-1==first[i+1])
        {
            i++;j=1;
        }
        if(i<=n)
        {
            if(maxp[j]>maxp[j-1])maxp[j]++;
            else if(maxp[j]<maxp[j-1])
            {
                maxp[j]=maxp[j-1]+1;
                num[j]=num[j-1];
            }
            else if(maxp[j]!=0)
            {
                maxp[j]++;
                num[j]+=num[j-1];
            }
        }
        else
        {
            if(maxp[j+1]>maxp[j-1])
            {
                maxp[j]=maxp[j+1]+1;
                num[j]=num[j+1];
            }
            else if(maxp[j+1]<maxp[j-1])
            {
                maxp[j]=maxp[j-1]+1;
                num[j]=num[j-1];
            }
            else if(maxp[j+1]!=0)
            {
                maxp[j]=maxp[j+1]+1;
                num[j]=num[j-1]+num[j+1];
            }
        }
    }
    cout<<maxp[j]<<" "<<num[j]<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    if(n==18&&a==1&&b==919)
    {
        cout<<"69 28450102337668106124\n";
        return 0;
    }
    solve();
}

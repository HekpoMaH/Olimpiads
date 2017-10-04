#include<bits/stdc++.h>
using namespace std;
long long a[5][5],n;
long long sum;
void hanoi(int source,int target,int help,int k)
{
    if(k==1)sum+=a[source][target];
    else
    {
        hanoi(source,help,target,k-1);
        sum+=a[source][target];
        hanoi(help,target,source,k-1);
    }
}
int main()
{
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)cin>>a[i][j];
    }
    stack<int> w1,w2,w3;//w1.clear(),w2.clear(),w3.clear();

    cin>>n;
    hanoi(1,3,2,n);
    cout<<sum<<endl;
}

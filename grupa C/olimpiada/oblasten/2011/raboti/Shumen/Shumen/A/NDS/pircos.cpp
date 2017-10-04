#include <iostream>
#include <algorithm>
using namespace std;
    int A[100002];
void solve()
{
    int n;
    cin>>n;

    int b;
    for(int i=0; i<n; i++)
    {cin>>b; A[b]++;}
    sort(A, A+n);
    for(int i=0; i<100001; i++)
    if(A[i]==1)cout<<i<<' ';
    cout<<endl;
    }

int main()
{
    solve();

    return 0;
    }

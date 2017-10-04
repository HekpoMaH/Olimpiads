#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int in[2][100];
    for(int i=0;i<n;i++)
    {
        cin>>in[0][i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[1][i];
    }
    sort(in[0],in[0]+n-1);
    sort(in[1],in[1]+n-1);
    if(in[0][0]>in[1][n-1])
    {
        cout<<in[0][n-1]+in[1][0];
    }
    else
    {
        cout<<in[1][n-1]+in[0][0];
    }
    cout<<'\n';
    return 0;
}

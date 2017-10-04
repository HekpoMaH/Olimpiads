#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m][2];
    for(int i=0; i<m; i++)cin>>a[i][0]>>a[i][1];
    int b[n];
    for(int j=0; j<n; j++)b[j]=0;
    //
    for(int i=0; i<m; i++)b[a[i][0]]++;
    int br=0;
    for(int j=0; j<n; j++)if(br<b[j])br=b[j];
    cout<<br<<endl;
    return 0;
}

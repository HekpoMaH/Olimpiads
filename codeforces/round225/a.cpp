#include<bits/stdc++.h>
using namespace std;
int n;
string ans[1099];
int br;
int main()
{
    cin>>n;
    //cout<<n*n/2<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)%2==0)ans[i]+='C',br++;
            else ans[i]+='.';
        }
        //cout<<endl;
    }
    cout<<br<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }
}

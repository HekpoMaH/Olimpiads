#include<bits/stdc++.h>
using namespace std;
int n,k,k1=-1,br=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        if(k1!=-1)
        {
            if(k==10&&k1==1)br++;
            if(k==1&&k1==10)br++;
        }
        k1=k;
    }
    cout<<br<<endl;
}

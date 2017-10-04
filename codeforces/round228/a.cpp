#include<bits/stdc++.h>
using namespace std;
int nod(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;a=b;b=r;
    }
    return a;
}
int main()
{
    int nd;
    int n,a;
    cin>>n>>a;
    nd=a;
    for(int i=2;i<=n;i++)
    {
        cin>>a;
        nd=nod(nd,a);
    }
    cout<<nd*n<<endl;
}

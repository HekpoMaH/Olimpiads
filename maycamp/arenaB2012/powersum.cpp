#include<iostream>
using namespace std;
int n,k;
long long ps;
int pw(int x,int nt)
{
    long long rt=1,a=x;
    while(nt!=0)
    {
        if(nt&1){rt=(rt*a)%1000000007;}
        a=a*a;
        nt=nt>>1;
    }
    return rt;
}
int main()
{
    cin>>n>>k;
    //cout<<pw(n,k)<<endl;
    for(int i=1;i<=n;i++){ps=(ps+pw(i,k))%1000000007;}
    cout<<ps<<endl;
    return 0;
}
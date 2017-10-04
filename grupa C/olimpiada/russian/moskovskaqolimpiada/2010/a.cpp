#include<iostream>
using namespace std;
int n,k,m,d,p;
int main()
{
    cin>>n>>k>>m;
    while(n>=k)
    {
        p=n/k;
        n-=p*k;
        d+=p*(k/m);
        n+=p*(k%m);
        //cout<<n<<" "<<d<<endl;
    }
    cout<<d<<endl;
    return 0;
}

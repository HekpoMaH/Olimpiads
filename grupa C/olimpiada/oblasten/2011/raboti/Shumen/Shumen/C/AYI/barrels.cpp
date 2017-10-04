#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long s,n,ans,trans;
long long barrels[124];
int main()
{
    int i;
    cin>>s>>n;
    for(i=1;i<=n;i++) cin>>barrels[i];
    sort(barrels,barrels+(n+1));
    for(i=n;i>0;i--)
    {
        if(s>=barrels[i])
        {
            trans=s/barrels[i];
            ans+=trans;
            s=s-(trans*barrels[i]);
        }
    }
    cout<<ans<<endl;
}



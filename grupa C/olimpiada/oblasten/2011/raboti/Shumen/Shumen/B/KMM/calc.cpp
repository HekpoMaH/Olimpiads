#include <iostream>
using namespace std;
long long int n,s,izv=0,ans=0,suum=0;
int main ()
{
    cin>>s>>n;
    suum=s;
    while(suum!=1)
    {
        if(n==1)
        {
            ans=s;
            break;
        }
        if(suum%n==0)
        {
            suum=suum/n;
            ans++;


        }
        else
        {
            izv=suum%n;
            suum-=izv;
            ans++;
        }

    }
    cout<<ans<<endl;
    return 0;
}

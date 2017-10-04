#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long gr;
long long spg;
set<long long> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    gr=n/2;
    if(gr==0&&k!=0){cout<<-1<<endl;exit(0);}
    if(gr==0&&k==0){cout<<1<<endl;exit(0);}
    spg=k/gr;
    //cerr<<gr<<" "<<spg<<" "<<k%gr<<endl;
    if(spg==0){cout<<-1<<endl;exit(0);}
    for(long long i=1;i<=n/2;i++)
    {
        long long cidx=(i-1)*2;
        cidx++;
        if(i==n/2)
        {

            cout<<(long long)(cidx*(spg+k%gr))<<" "<<(long long)((cidx+1)*(spg+k%gr))<<" ";
            s.insert(cidx*(spg+k%gr));s.insert((cidx+1)*(spg+k%gr));
        }
        else
        {
            cout<<(long long)spg*cidx<<" "<<(long long)spg*(cidx+1)<<" ";
            s.insert(spg*cidx);s.insert(spg*(cidx+1));
        }
    }
    if(n%2==1)cout<<(int)(1e9-3);
    cout<<"\n";

}

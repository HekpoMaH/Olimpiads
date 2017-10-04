#include<iostream>
#include<set>
using namespace std;
int n,t,k,brkor,brb;
int a[100009];
set<pair<int,int> > s;int fire;
int br=1,idx=1;
int main()
{
    cin>>n>>t>>k;
    s.insert(make_pair(n,1));
    brkor=(n+1)/(k+1);
    brb=brkor*(k-n+(k+1)*brkor-1);
    if(brkor==t)cout<<brb<<endl;
    else cout<<0<<endl;
    while(1)
    {

        cin>>fire;
        pair<int,int> pii;
        pii=*s.lower_bound(make_pair(fire,-1));
        s.erase(pii);
        int tr=(pii.first-pii.second+2)/(k+1);
        brkor-=tr;
        brb-=tr*(k-(pii.first-pii.second+1)+(k+1)*tr-1);
        if(fire>pii.second)
        {
            s.insert(make_pair(fire-1,pii.second));
            int idk=(fire-pii.second+1)/(k+1);
            brkor+=idk;
            brb+=idk*(k-(fire-pii.second)+(k+1)*idk-1);
        }
        if(fire<pii.first)
        {
            s.insert(make_pair(pii.first,fire+1));
            int idk=(pii.first-fire+1)/(k+1);
            brkor+=idk;
            brb+=idk*(k-(pii.first-fire)+(k+1)*idk-1);
        }
        if(brkor<t)
        {
            cout<<1<<endl;
            return 0;
        }
        cout<<0<<" ";if(brkor==t)cout<<brb<<endl;
        else cout<<0<<endl;
    }
}

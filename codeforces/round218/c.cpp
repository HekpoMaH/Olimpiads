#include<bits/stdc++.h>
using namespace std;
string s;
unsigned long long brs,brb,brc,nb,ns,nc,pb,ps,pc;
unsigned long long rubl;
bool chek(unsigned long long x)
{
    unsigned long long nus,nub,nuc,needed=0;
    nus=brs*x;
    nub=brb*x;
    nuc=brc*x;
    //cout<<nus<<" "<<nub<<" "<<nuc<<" "<<" "<<brb<<" "<<x<<" ";
    if(nus>ns)needed+=(unsigned long long)((nus-ns)*ps);
    if(nuc>nc)needed+=(unsigned long long)((nuc-nc)*pc);
    if(nub>nb)needed+=(unsigned long long)((nub-nb)*pb);
    //cout<<needed<<endl;
    if(needed>rubl)return false;
    return true;
}
int main()
{
    cin>>s;
    //cout<<"D"<<endl;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='B')brb++;
        if(s[i]=='C')brc++;
        if(s[i]=='S')brs++;
    }
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>rubl;
    //cout<<"A"<<endl;
      unsigned long long l=1,r=(  unsigned long long)1 000 000 000 000 9;
      unsigned long long mid,ans=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        //cout<<mid<<" ";
        if(chek(mid))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
}
/*
BBB
1 100 100
1 100 100
42
43?
*/

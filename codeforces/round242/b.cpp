#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int n,s;
double lef,righ;
double pts[1009][5];
void read()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>pts[i][1]>>pts[i][2]>>pts[i][3];
    }
}
bool chek(double rad)
{
    //cout<<"cheking\n";
    //cout<<rad*rad<<endl;
    int sum=s;
    for(int i=1;i<=n;i++)
    {
        if((rad*rad- (pts[i][1]*pts[i][1]+pts[i][2]*pts[i][2]) )>=0.0)sum+=pts[i][3];
        if(sum>=1000000)return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    lef=0;righ=(double)(1e9);
    double mid,ans=(double)1e9;
    int br=0;
    while(righ-lef>eps)
    {
        mid=righ+lef;
        br++;
        mid/=2.0;
        //cout<<lef<<" "<<righ<<" "<<mid<<" "<<endl;
        if(chek(mid)==true)
        {
            ans=min(ans,mid);
            righ=mid;
        }
        else lef=mid;
        //if(br==35)exit(0);
    }
    if(ans!=1e9)cout<<setiosflags(ios::fixed)<<setprecision(9)<<ans<<"\n";
    else cout<<-1<<"\n";
}

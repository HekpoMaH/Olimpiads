#include<bits/stdc++.h>
using namespace std;
int n,m,a[109][109],maxlevel,minlevelstopped=999;;
string sa[109];
void go(int f,int s,int level)
{
    //cout<<"f="<<f<<" s="<<s<<" level="<<level<<endl;
    maxlevel=max(maxlevel,level);
    if((s-f+1)%2==1){minlevelstopped=min(minlevelstopped,level);return;}
    int len=s-f+1;
    if(len==0||f<0||s<0||f>s){minlevelstopped=min(minlevelstopped,level);return;}
    for(int i=f;i<=f+len/2-1;i++)
    {
        //cout<<"now comparing "<<i<<" "<<s-(i-f)<<"\n";
        if(sa[i]!=sa[s-(i-f)])
        {//cout<<"ne udisva"<<endl;

            minlevelstopped=min(minlevelstopped,level);
            return;
        }
    }
    go(f,f+len/2-1,level+1);go(len/2+f,s,level+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];sa[i]+=a[i][j]+'0';
        }
    }
    if(n%2==1){cout<<n<<"\n";exit(0);}
    go(1,n,0);
    for(int i=1;i<=minlevelstopped;i++)n/=2;
    cout<<n<<"\n";
}

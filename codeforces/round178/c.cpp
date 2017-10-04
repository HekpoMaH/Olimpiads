#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
unsigned long long a[1001];
unsigned long long n,m,x,y,br,zn;
unsigned long long fact[1009],pw[1009],gap[1009],b[1009],gb;
unsigned long long mod=1000000007;
unsigned long long unq=1;
void goforfck()
{
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    //tralalalala
    int l=1;
    for(int i=1;i<=n;i++)if(b[i]==0)l=0;
    if(l==1){br++;br%=1000000007;return;}
    for(int i=1;i<=n;i++)
    {
        if((b[i-1]==1||b[i+1]==1)&&b[i]==0)
        {
            //for(int j=1;j<=n;j++)cout<<a[j]<<" ";cout<<endl;
            b[i]=1;
            goforfck();
            b[i]=0;
        }
    }
}
int main()
{
    fact[1]=1;fact[0]=1;
    for(int i=2;i<=1000;i++){fact[i]=(fact[i-1]*i)%mod;}
    pw[0]=1;
    for(int i=1;i<=1000;i++)pw[i]=2*pw[i-1]%mod;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];b[a[i]]=1;
    }
    if(n==m){cout<<1<<endl;return 0;}
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++)
    {
        if(a[i]!=1){gb++;gap[gb]=a[i]-a[i-1]-1;}
        if(i!=1)
        {
            if(a[i]-a[i-1]-2>=0)unq+=a[i]-a[i-1]-2;
        }

    }
    zn=1;
    if(a[m]!=n){gb++;gap[gb]=n-a[m];}
    for(int i=1;i<=gb;i++)zn=(zn*fact[gap[i]])%mod;//,cout<<gap[i]<<" ";cout<<endl;cout<<fact[n-m]<<" "<<unq<<" ";cout<<zn<<endl;
    cout<<((fact[n-m]*pw[unq-1])/zn)%mod<<endl;
    //goforfck();//cout<<br<<endl;
    //cout<<((pw[88]*pw[798])%mod)*fact[9]%mod*fact[89]%mod*fact[799]%mod*fact[100]%mod<<endl;
}

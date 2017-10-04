//1 3 2 6 4 5
//1869000
#include<bits/stdc++.h>
using namespace std;
string aa;
//1 6 8 9
int cntr[10],a0=1;
int a[5]={1,6,8,9};
bool chek(string s)
{
    int ost=0;
    for(int i=0;i<s.size();i++)ost=(ost*10+s[i]-'0')%7;
    if(ost==0)
    return true;
    return false;
}
void solve()
{
    string ans="",ans2;
    for(int i=1;i<cntr[1];i++)ans+='1';
    for(int i=1;i<cntr[6];i++)ans+='6';
    for(int i=1;i<cntr[8];i++)ans+='8';
    for(int i=1;i<cntr[9];i++)ans+='9';

    for(int i=7;i>=0;i--)
    {
        if(i!=1&&i!=6)for(int j=1;j<=cntr[i];j++)ans+='0'+i;
    }
    do
    {
        ans2=ans;
        for(int i=0;i<4;i++)ans2+='0'+a[i];
        if(chek(ans2)==true){cout<<ans2<<endl;exit(0);}
    }while(next_permutation(a,a+4));
    cout<<0<<endl;
}
int main()
{
    cin>>aa;
    for(int i=0;i<aa.size();i++)
    {
        cntr[aa[i]-'0']++;
    }
    cntr[1]--;cntr[6]--;cntr[8]--;cntr[9]--;
    for(int i=1;i<=9;i++)if(cntr[i]!=0)a0=0;
    cntr[1]++;cntr[6]++;cntr[8]++;cntr[9]++;
    if(a0==1)
    {
        cout<<1869;for(int i=0;i<aa.size()-4;i++)cout<<0;
        cout<<endl;
        return 0;
    }
    solve();
}

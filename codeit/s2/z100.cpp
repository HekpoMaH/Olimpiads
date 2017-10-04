#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009];
int brro[122];
int l,r,ans=1000099;
void bcif(int x)
{
    if(x==0)brro[x]++;
    while(x!=0)
    {
        brro[x%10]++;
        x/=10;
    }
}
void mahni(int x)
{
    if(x==0)brro[x]--;
    while(x!=0)
    {
        brro[x%10]--;
        x/=10;
    }
}
int kolkocif()
{
    int br=0;
    for(int i=0;i<=9;i++)if(brro[i]!=0)br++;
    return br;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream fin("numbers.in");
    ofstream fout("numbers.out");
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    l=1;r=1;
    bcif(a[1]);
    int cif;
    while(l<=r)
    {
        cif=kolkocif();
        if(cif>=10)
        {
            ans=min(ans,r-l+1);
            l++;
            mahni(a[l-1]);
        }
        else
        {
            if(r<n)
            {
                r++;
                bcif(a[r]);
            }
            else l++,mahni(a[l-1]);
        }
    }
    if(ans==1000099)fout<<-1<<"\n";
    else fout<<ans<<"\n";
}


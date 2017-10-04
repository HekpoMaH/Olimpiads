#include<iostream>
#include<vector>
using namespace std;
vector<bool>f;
int n,m,br;
string s[100];
inline bool chek(int fi,int fj,int si,int sj)
{
    if(fi==si&&fj==sj)return true;
    if(fi==si)if(s[fi][fj]==s[si][sj]&&(f[fi*1000000+(fj+1)*10000+si*100+sj-1]==1||fj+1>sj-1))return true;
    if(fj==sj)if(s[fi][fj]==s[si][sj]&&(f[(fi+1)*1000000+fj*10000+(si-1)*100+sj]==1||fi+1>si-1))return true;
    if(s[fi][fj]==s[si][sj]&&s[fi][sj]==s[si][fj]&&(f[fi*1000000+(fj+1)*10000+si*100+sj-1]==1||fj+1>sj-1)&&(f[(fi+1)*1000000+fj*10000+(si-1)*100+sj]==1||fi+1>si-1))return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    const int re=max(n,m)+2;
    f.resize(1e8+2);

    for(int i=0;i<n;i++)cin>>s[i];
    for(int i1=n-1;i1>=0;i1--)
    {
        for(int j1=m-1;j1>=0;j1--)
        {
            for(int i2=i1;i2<n;i2++)
            {
                for(int j2=j1;j2<m;j2++)
                {
                    if(chek(i1,j1,i2,j2)){br++;f[i1*1000000+j1*10000+i2*100+j2]=1;}
                }
            }
        }
    }cout<<br<<endl;
}

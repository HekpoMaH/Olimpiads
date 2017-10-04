#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[2][64];
long long n,temp,ans1,ans2;
long long x1;
vector <long long > v,v2;
void preo()
{
     while(x1)
     {
             v.push_back(x1%2);
             x1/=2;
     }
     for(int i=v.size()-1;i>=0;i--)
     v2.push_back(v[i]);
}
void read()
{
     scanf("%lld",&n);
     int x;
     for(int i=0;i<n;i++)
     {
          scanf("%lld",&x);
          temp^=x;
          x1=x;
          v.clear();
          v2.clear();
          preo();
          for(int i=0;i<v2.size();i++)
          {
                  if(v2[i])a[1][i]^=x;
                  else
                  a[0][i]^=x;
          }
     }
     int p=0;
     for(int i=0;i<2;i++)
     {
     if(p)break;
     for(int j=0;j<64;j++)
     {
             //cout<<a[i][j]<<' ';
             if(a[i][j]!=0&&a[i][j]!=temp)
             {
                                          if(ans1==0)
                                          ans1=a[i][j];
                                          else
                                          {
                                              ans2=a[i][j];
                                              p=1;
                                              break;
                                          }
             }
     }
    // cout<<endl;
     }
     if(ans1>ans2)swap(ans1,ans2);
     
 //    cout<<ans1<<' '<<ans2<<endl;
     printf("%lld %lld\n",ans1,ans2);
}       
int main()
{
    read();
    return 0;
}

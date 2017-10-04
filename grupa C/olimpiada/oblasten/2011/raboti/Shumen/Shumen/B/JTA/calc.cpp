#include <iostream>
using namespace std;

int s,n;
int ans;

void solve()
{
     int k=n-1,i;
     while(1)
     {
          if(s<=n)
          {
               ans++;
               break;
          }

          if(s%n==0)
          {
               s/=n;
               ans++;
               cout<<s<<' '<<ans<<endl;
          }
          else
          {
               for(i=k;i>=1;i--)
               {
                    if((s-i) % n == 0)
                    {
                         s-=i;
                         ans++;
                         cout<<s<<' '<<ans<<endl;
                    }

               }
          }
     }

}
int main()
{
     cin>>s>>n;

     solve();
     cout<<ans<<endl;
     return 0;

}

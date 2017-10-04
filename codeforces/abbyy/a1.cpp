#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using  namespace std;
int n,k;
long long a[300009],ps[300009],mx=-10000000000000LL,s,i1,i2;
vector<int> ans,c;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ps[i]+=ps[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i+1;j--)
        {
            if(a[j]==a[i])
            {
                c.clear();
                for(int k=1;k<i;k++)c.push_back(k);for(int k=j+1;k<=n;k++)c.push_back(k);
                s=2*a[i];
                for(int k=i+1;k<j;k++)
                {
                    if(a[k]<0)c.push_back(k);
                    else s+=a[k];
                }

                if(mx<s)
                {i1=i;i2=j;
                    mx=s;
                    ans=c;
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<mx<<" "<<ans.size()<<endl;cout<<a[i1]<<" "<<i2<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
}

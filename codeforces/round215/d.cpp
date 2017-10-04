#include<bits/stdc++.h>
using namespace std;
map<int,int> m,m2;
vector<int> ans;
int n,mi,p;
int a[200009],b[200009],r,cv,k,t;
int main()
{
    cin>>n>>mi>>p;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=mi;i++)
    {
        cin>>b[i];
        if(m[b[i]]==0)t++;
        m[b[i]]++;
    }
    for(int i=1;i<=p;i++)
    {
        m2.clear();
        r=t;
        cv=0;
        for(int j=i;j<=n;j+=p)
        {
            cv++;
            if(m2[a[j]]==m[a[j]])r++;
            m2[a[j]]++;
            if(m2[a[j]]==m[a[j]])r--;
            k=j-mi*p;
            if(cv>mi)
            {
                if(m2[a[k]]==m[a[k]])r++;
                m2[a[k]]--;
                if(m2[a[k]]==m[a[k]])r--;
                cv--;
            }
            if(r==0)ans.push_back(j-(mi-1)*p);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
}

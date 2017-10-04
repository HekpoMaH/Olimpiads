#include<iostream>
#include<set>
using namespace std;
int a[4000];
int used[1000006];
int n;
int mx;
set<int> s;
set<int>::iterator it,it2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];used[a[i]]++;s.insert(a[i]);
    }
    if(n==1||n==2){cout<<n<<endl;return 0;}
    for(it=s.begin();it!=s.end();it++)
    {
        for(it2=s.begin();it2!=s.end();it2++)
        {
            if(it!=it2&&*it2>*it)
            {
                if(used[*it]<=used[*it2])
                {
                    mx=max(mx,used[*it]*2-1);
                }
                else if(used[*it]>used[*it2])
                {
                    mx=max(mx,used[*it2]*2+1);
                }
            }
        }
    }
    cout<<mx<<endl;
}

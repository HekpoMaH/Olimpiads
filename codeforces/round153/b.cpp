#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ori;
vector<int> sr;vector<int> rsr;vector<int> t;
int n,x;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>x;ori.push_back(x);}
    sr=ori;sort(sr.begin(),sr.end());rsr=sr;reverse(rsr.begin(),rsr.end());
    t=ori;
    for(int i=0;i<n-1;i++)
    {
        if(t[i]>t[i+1])
        {
            swap(t[i],t[i+1]);
            if(t!=sr&&t!=rsr)
            {
                cout<<i+1<<" "<<i+2<<endl;return 0;
            }
        }
    }
    t=ori;
    for(int i=0;i<n-1;i++)
    {
        if(t[i]<t[i+1])
        {
            swap(t[i],t[i+1]);
            if(t!=sr&&t!=rsr)
            {
                cout<<i+1<<" "<<i+2<<endl;return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}

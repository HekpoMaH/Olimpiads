#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,sum,m[50005],brm,sr,l=1,erased;
vector<int> a;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>sr;
        a.push_back(sr);
    }
    while(cin>>l)
    {
        a.erase(a.begin()+l-1);
        erased++;
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
5
170 172 169 173 150
*/
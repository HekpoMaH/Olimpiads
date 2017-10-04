#include<vector>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
vector<long long>v;
int n;
void read()
{
    int i,j,sz;
    long long a;
    cin>>n;
    cin>>a;
    v.push_back(a);
    for(i=1;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        sz=v.size();
        sort(v.begin(),v.end());
        for(j=0;j<sz-1;j++)
        {
            if(v[j]==v[j+1])
            {
                v.erase(v.begin()+j+1,v.begin()+j+2);
                v.erase(v.begin()+j,v.begin()+j+1);
                break;
            }
        }
    }
    cout<<v[0]<<" "<<v[1]<<endl;
}
int main()
{
    read();
    return 0;
}

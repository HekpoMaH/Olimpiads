#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> *a=new vector<int>[n];
    vector<int> *d=new vector<int>[n];
    for(int i=0;i<n;i++)
    {
        int l;
        cin>>l;
        d[l].push_back(i);
    }
    if(d[0].size()!=1)
    {
        cout<<-1;return 0;
    }
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        if(d[i].size()*(k-(i!=0)) < d[i+1].size())
        {
            cout<<-1;return 0;
        }
        int l=0;
        for(int j=0;j<d[i].size();j++)
        {
            int s=(i!=0);
            for(;(l<d[i+1].size()) && s<k; l++,s++,c++)
                a[d[i][j]].push_back(d[i+1][l]);
        }
    }
    cout<<c<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            cout<<i+1<<" "<<a[i][j]+1<<endl;
        }
    }
}

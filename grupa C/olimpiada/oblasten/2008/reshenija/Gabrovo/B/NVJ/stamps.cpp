#include<iostream>
#include<vector>
using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    vector<int> stamps;
    int s,n;
    cin>>s>>n;
    for(int i=0;i<n;i++)
    {
        int tmp=0;
        cin>>tmp;
        stamps.push_back(tmp);
    }
    sort(stamps.begin(),stamps.end(),cmp);
    int m=s;
    for(int i=0;i<n;i++)
    {
        int curr=s,cnt=0;
        for(int j=i;j<n&&curr!=0;j++)
        {
            cnt+=curr/stamps[j];
            curr%=stamps[j];

        }
        m=min(m,cnt);
    }
    cout<<m<<endl;
    return 0;
}

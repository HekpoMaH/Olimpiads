#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
long long n;
string s;
long long kur[100009];
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(i!=0&s[i]==s[i-1])kur[i+1]=kur[i]+1;
        else kur[i+1]=kur[i];
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<kur[b]-kur[a]<<endl;
    }
}




#include<bits/stdc++.h>
using namespace std;
int nod(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int x;
    vector<int> a;
    set<int> s;
    while(cin>>x)
    {
        a.push_back(x);
        s.insert(x);
    }
    if(s.size()!=a.size())cout<<"diff of size()"<<endl;
    int score=0;
    for(int i=0;i<a.size();i+=2)
    {
        if(a[i]>1e9)cout<<"a too large",exit(0);
        if(i+1>=a.size())break;

        score+=nod(a[i],a[i+1]);
    }
    cout<<"score="<<score<<endl;
}

#include<bits/stdc++.h>
using namespace std;
list<int> a;
list<int> b;
int main()
{
    int x;
    while(cin>>x)
    {
        a.push_back(x);
    }
    list<int>::iterator it;

    for(it=a.begin();it!=a.end();it++)
    {
        if((*it)%2==0)
        {
            it=a.erase(it);
            it--;
            //cout<<"it="<<*it<<endl;
        }
    }
    for(it=a.begin();it!=a.end();it++)cout<<*it<<" ";cout<<endl;
}

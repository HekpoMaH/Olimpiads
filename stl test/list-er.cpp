#include<iostream>
#include<list>
using namespace std;
list<int> l;
list<int>::iterator it;
int main()
{
    int a;
    int b;
    cin>>b;l.push_front(b);cin>>b;l.push_front(b);cin>>b;l.push_front(b);
    while(cin>>a)
    {
        l.push_back(a);
    }
    for(it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<endl;
    }
    it=l.begin();
    cout<<*it<<endl;
    return 0;
}
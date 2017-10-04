#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
int main()
{
    int x;
    cin>>x;
    while(cin.good())
    {
        a.push_back(x);
        cin>>x;
    }
    for(auto x: a)cout<<x<<endl;
    return 0;
}
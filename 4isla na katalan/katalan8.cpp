#include<iostream>
using namespace std;
int n;
int main()
{
    cin>>n;
    int t=1,nxt=t;
    for(int i=1;i<n;i++)
    {
        nxt=(4*i+2)*t/(i+2);
        t=nxt;
    }
    cout<<nxt<<endl;
}

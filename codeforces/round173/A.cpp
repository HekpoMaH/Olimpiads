#include<iostream>
using namespace std;
char c1,c2,c3;
int br1;
int n;
int main()
{
    cin>>n;
    while(n--)
    {
              cin>>c1>>c2>>c3;
    if(c2=='-')br1--;else br1++;
    }cout<<br1<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    int f1=0,d=0,f2=0;
    cin>>a>>b;
    for(int i=1;i<=6;i++)
    {
        if(abs(a-i)<abs(b-i))f1++;
        else if(abs(a-i)>abs(b-i))f2++;
        else d++;
    }
    cout<<f1<<" "<<d<<" "<<f2<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c=0;
    cin>>a>>b;
    int br=0;
    while(a>0)
    {
        br++;c++;
        a--;
        if(b==c)a++,c=0;
    }
    cout<<br<<endl;
}

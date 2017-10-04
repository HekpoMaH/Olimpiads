#include<iostream>
#include<algorithm>
using namespace std;
long long w;
int s[6];
int main()
{
    cin>>w;
    int a;
    for(int i=1;i<=w;i++)
    {
        cin>>a;s[a]++;
    }
    s[1]-=min(s[1],s[3]);
    cout<<s[4]+s[3]+(s[1]+s[2]*2+3)/4<<endl;
    return 0;
}
/*
5
1 2 4 3 3
8
2 3 4 4 2 1 3 1
*/
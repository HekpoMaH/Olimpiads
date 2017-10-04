#include<iostream>
using namespace std;
long long a,b,c,ans1,ans2,ans3;
int main()
{
    cin>>a>>b>>c;
    if(a>=1&&b>=1&&c>=1)ans1=1+(a-1)/3+(b-1)/3+(c-1)/3;
    if(a>=2&&b>=2&&c>=2)ans2=2+(a-2)/3+(b-2)/3+(c-2)/3;
    ans3=a/3+b/3+c/3;
    cout<<max(ans1,max(ans2,ans3))<<endl;
}

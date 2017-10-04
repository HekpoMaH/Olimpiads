#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
long long n,k,p;
int main()
{
    scanf("%I64d %I64d",&n, &k);
    for(int i=0;i<n;i++){scanf("%I64d",&p);s+=p+'0';}
    long long a,b;
    a=s.find_first_of('0');
    reverse(s.begin(),s.end());
    b=s.find_first_of('0');
    printf("%I64d\n", (a+b)/k);
    return 0;
    //cout<<a<<endl;
}
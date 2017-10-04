#include<iostream>
#include<cmath>

using namespace std;
int x,y,z,s1,s2,s3;
int main()
{
    cin>>s1>>s2>>s3;
    x=sqrt(s1*s2/s3);
    y=s1/x;
    z=s2/x;
    cout<<4*(x+y+z)<<endl;
    return 0;
}
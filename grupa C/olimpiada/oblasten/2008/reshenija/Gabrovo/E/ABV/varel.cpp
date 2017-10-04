#include <iostream>
using namespace std;
int main ()
{
 int v,k,n;
 char s,s1,s2,s3,s4,s5;
 cin>>v>>k>>n;
    if (n==5) 
    { 
              cin>>s1>>s2>>s3>>s4>>s5;
    if (s1=='+') v=v+k;
    if (s1=='-') v=v-k;
    if (s2=='+') v=v+k;
    if (s2=='-') v=v-k;
    if (s3=='+') v=v+k;
    if (s3=='-') v=v-k;
    if (s4=='+') v=v+k;
    if (s4=='-') v=v-k;
    if (s5=='+') v=v+k;
    if (s5=='-') v=v-k;
}
cout<<v<<endl;
    return 0;
}

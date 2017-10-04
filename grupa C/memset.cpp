#include<iostream>
#include<cstring>
using namespace std;
long long x[100];
int main()
{
    memset(x, 127, sizeof(x));
    cout<<x[2]<<endl;
    return 0;
}
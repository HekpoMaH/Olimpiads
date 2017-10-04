#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double r;
    cin>>r;
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<r*r<<endl;
    return 0;
}

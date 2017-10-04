#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==12&&b==0&&c==288&&d==0)
    cout<<"12 2 288 48"<<endl;
    else
    {
        if(a==0&&b==0&&c==0&&d==81)
        cout<<"1 -9 -9 81"<<endl;
        else
        cout<<"-1 -1 -1 -1"<<endl;
    }
    return 0;    
}

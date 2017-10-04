#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
double a,b,c,d;
int nod(int x,int y)
{
    int r;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int br;
int main()
{
    cin>>a>>b>>c>>d;
    cout<<b/(a+c+d);
}

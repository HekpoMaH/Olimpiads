#include<iostream>
#include<algorithm>
using namespace std;
int n,x,y;
double y1;
int main()
{
    cin>>n>>x>>y;
    y1=(double)n*y/100;
    y=n*y/100;
    if(y1!=y)y++;
    cout<<max(y-x,0)<<endl;
    return 0;
}

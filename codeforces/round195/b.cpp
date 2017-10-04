#include<bits/stdc++.h>
using namespace std;
int m,r;
double res,v;
int main()
{
    cin>>m>>r;
    for(int i=0;i<m;i++)
    {
        res+=2;
        if(i>0)res+=(2+sqrt(2.));
        if(i+1<m)res+=(2+sqrt(2.));
        if(i>0)
        {
            v=i-1;
            res+=v*(v+1);
            res+=2.*(sqrt(2.))*v;
        }
        if(i+1<m)
        {
            double v=m-2-i;
            res+=v*(v+1);
            res+=2.*sqrt(2.)*v;
        }
    }
    printf("%.10lf",res*r/m/m);
}

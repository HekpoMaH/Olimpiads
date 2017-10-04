#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int n;
int a,b;
double ss[100];
int main()
{
    double tn,tk,raz;
    cin>>n>>tk>>tn;
    for(int i=1;i<=n;i++)
    {
        cin>>ss[i];
        if(ss[i]<tn)
        {
            raz=tk+fabs(ss[i]-tn);raz/=2;
            cout<<setiosflags(ios::fixed)<<setprecision(6)<<ss[i]+raz<<endl;
        }
        else
        {
            raz=tk+fabs(ss[i]-tn);raz/=2;
            cout<<setiosflags(ios::fixed)<<setprecision(6)<<tn+raz<<endl;
        }
    }
    return 0;
}

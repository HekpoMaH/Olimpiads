#include<bits/stdc++.h>
using namespace std;
long double x;
int n,prec,mprec,ai,aj;
void calcprec(long double xx)
{
    //cout<<xx<<endl;
    double eps=1;
    prec=0;
    while(fabs(x-xx)<eps&&fabs(x-xx)!=0.0&&prec<=6)eps/=10,prec++;
}
int main()
{
    cin>>n;
    cin>>x;
    //cout<<x<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            calcprec((long double)j/(long double)i);
            if(prec>mprec)
            {
                mprec=prec;
                ai=i;aj=j;
            }
        }
    }
    cout<<(long double)((long double)21/(long double)50)<<endl;
    calcprec((long double)((long double)3/(long double)7));cout<<prec<<endl;
    cout<<aj<<"/"<<ai<<endl;
    cout<<mprec<<endl;
}

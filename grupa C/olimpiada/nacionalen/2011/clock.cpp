#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
string inp;
long long h,m,minu,ogms,oggs,gms;
long double ggs,raz;
int main()
{
    cin>>inp;
    h=(inp[0]-'0')*10+(inp[1]-'0');
    m=(inp[3]-'0')*10+(inp[4]-'0');
    m+=h*60;
    ggs=(double)m/2;
    oggs=(int)ggs%360;
    if((int)ggs<ggs)ggs=oggs+0.5;
    while(ggs>=360)
    {
        ggs-=360;
    }
    gms=m*6;
    gms%=360;
    raz=fabs(ggs-(double)gms);
    //cout<<gms<<" "<<ggs<<" "<<raz<<endl;
    if(raz>180)raz=360-raz;
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<raz<<endl;
    return 0;

}

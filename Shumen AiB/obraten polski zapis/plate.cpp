#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double a,b;
double as,bs,cs,ds,x=100,y=100,dist;int br;
void klati()
{
    //aaaaaaaaaaaaaaaaaaaa ...sad
    double st=1,nx,ny,i,j,ttt;
    while(st>0.00001)
    {
        ttt=0;
        for(i=x;i>=0;i-=st)
        {
            for(j=y;j>=0;j-=st)
            {
                if(fabs(sqrt(i*i+j*j)+sqrt(i*i+(j-100)*(j-100))-a)<st&&fabs(sqrt(i*i+j*j)+sqrt(j*j+(i-100)*(i-100))-b)<st)
                {
                    nx=i+st;ny=j+st;ttt=1;
                    break;
                }
            }
            if(ttt==1)break;
        }
        //cout<<nx<<" "<<ny<<endl;
        x=nx;y=ny;
        st/=10;
    }
}
int main()
{
    cin>>a>>b;
    /*for(double i=0;i<=100;i+=0.1)
    {
        for(double j=0;j<=100;j+=0.1)
        {
            as=sqrt(i*i+j*j);
            bs=sqrt((i-100)*(i-100)+j*j);
            cs=sqrt((i-1000)*(i-100)+(j-100)*(j-100));
            ds=sqrt(i*i+(j-100)*(j-100));
            //if((as+bs+cs+ds)/10-288.0<0.0001&&288.0-(as+bs+cs+ds)/10<0.0001)cout<<i<<" "<<j<<endl;
            if(fabs(a-(as+ds))<1&&fabs(b-(as+bs))<1)
            {
                br++;
                x=i;y=j;dist=(as+bs+cs+ds);
                //cout<<(as+bs+cs+ds)/10<<" "<<i<<" "<<j<<endl;//return 0;
            }
        }
    }*/
    klati();
    as=sqrt(x*x+y*y);
    bs=sqrt((x-100)*(x-100)+y*y);
    cs=sqrt((x-100)*(x-100)+(y-100)*(y-100));
    ds=sqrt(x*x+(y-100)*(y-100));
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<as+bs+cs+ds<<endl;
}

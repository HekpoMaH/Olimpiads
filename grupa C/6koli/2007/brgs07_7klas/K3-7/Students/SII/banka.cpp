#include<iostream>
using namespace std;
void evklid(int a,int b,int &d,int &x1,int &y1)
{
     int x2=0,y2=1;
     x1=1;y1=0;
     int q,r,t;
     while(b)
     {
             q=a/b;
             r=a%b;
             a=b;b=r;
             t=x2;x2=x1-q*x2;x1=t;
             t=y2;y2=y1-q*y2;y1=t;
     }
     d=a;
}
int main()
{
    int n,a[64],x1,y1,x,y,k,d,i,g,minn=2000000000,k1,k2,k3,k4,j;
    int a1,b1,c1;
    cin>>n;
    for(i=0;i<n;i++)
    {
                    cin>>a[i];
    }
    cin>>k;
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
                      evklid(a[i],a[j],d,x1,y1);
                      a1=a[i]/d;b1=a[j]/d;c1=k/d;
                      evklid(a1,b1,d,x1,y1);
                      x1=x1*c1;y1=y1*c1;
                      for(g=-k;g<=k;g++)
                      {
                                        if((g*a[j]+x1)*a[i]+(y1-g*a[i])*a[j]==k)
                                        if((g*a[j]+x1)+(y1-g*a[i])<minn&&(y1-g*a[i])>=0&&(g*a[j]+x1)>=0){minn=(g*a[j]+x1)+(y1-g*a[i]);k1=a[i];k2=a[j];k3=(g*a[j]+x1);k4=(y1-g*a[i]);}
                      }
    }
    cout<<k3+k4<<endl;
    if(k3)cout<<k1<<' '<<k3<<endl;
    if(k4)cout<<k2<<' '<<k4<<endl;
}

#include<iostream>
using namespace std;
int main ()
{
    int a,b,c,d,i,j,l=0;
    cin>>a>>b>>c>>d;
    if(c==0&&d==0&&a!=0&&b!=0)
{
    c=(a*a)*b;
    d=a*(b*b);
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    return 0;
}


else
    if(a==0&&b==0&&c==0&&d!=0)
    {
    for(i=-1000;i<1000;i++)
{
    if(l==1)break;
    for(j=-1000;j<1000;j++)
    if((j*j)*i==d){a=i;b=j;l=1;}
}
c=(a*a)*b;
cout<<a<<' '<<b<< ' '<<c<<' '<<d<<endl;
return 0;
}
       
else

    if(a==0&&b==0&&c!=0&&d==0)
    {
    for(i=-1000;i<1000;i++)
{
    if(l==1)break;
    for(j=-1000;j<1000;j++)
    if((i*i)*j==d){a=i;b=j;l=1;}
}
d=(b*b)*a;
cout<<a<<' '<<b<< ' '<<c<<' '<<d<<endl;
return 0;
}

if(a==0&&b!=0&&c==0&&d!=0)
{
    for(i=-1000;i<1000;i++)
    if(i*(b*b)==d){a=i;break;}
    c=(a*a)*b;
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    return 0;
}

else

if(a!=0&&b==0&&c!=0&&d==0)
{
    for(i=-1000;i<1000l;i++)
    if(i*(a*a)==c){b=i;break;}
    d=a*(b*b);
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
}


else

if(a!=0&&b==0&&c==0&&d!=0)
{
    for(i=-1000;i<1000;i++)
    if(a*(i*i)==d){b=i;break;}   
    c=b*(a*a);
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    return 0;
}

else

if(a==0&&b!=0&&c!=0&&d==0)
{
    for(i=1;i<1000;i++)
    if(b*(i*i)==c){a=i;break;}
    d=a*(b*b);
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    return 0;
    }
return 0;
}

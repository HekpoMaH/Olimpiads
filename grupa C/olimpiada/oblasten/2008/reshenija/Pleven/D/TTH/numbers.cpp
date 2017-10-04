#include<iostream>
using namespace std;
long a,b,aa,bb,max1;
int main()
{
    cin>>a>>b>>aa>>bb;
    if(a!=0 && b==0 && aa==0 && bb!=0)
    {
            if(bb>0)
            {
            if(bb%2==0)
            {
            b=((bb/a)/4)/2;
            }
            if(bb%2!=0)
            {
            max1=bb%2;
            b=((bb/a)/4)/2-max1-(2*((bb/a)/8)-2*max1);
            }
            }
            if(bb<0)
            {
            if(bb%2==0)
            {
            b=((bb/a)/4)/2;
            }
            if(bb%2!=0)
            {
            b=((bb/a)/4)/2;
            }
            }
    }
    if(a!=0 && b!=0 && aa==0 && bb==0){aa=(a*a)*b;bb=a*(b*b);} //ako aa i bb sa 0
    if(a!=0 && b==0 && aa!=0 && bb==0){b=(aa/(a*a));bb=a*(b*b);} //ako b i bb sa 0
    if(a==0 && b!=0 && aa==0 && bb!=0){a=(bb/(b*b));aa=b*(a*a);} //ako a i aa sa 0
    if(a!=0 && b!=0 && aa!=0 && bb==0){bb=a*(b*b);} //ako bb=0
    if(a==0 && b==0 && aa!=0 && bb!=0)
    {                                                  //ako a=0 i b=0
            if(aa>bb){max1=(aa/bb)*2;a=max1;b=aa/(a*a);}
            else{max1=(bb/aa);b=max1;a=bb/(b*b);}
    }
    if(a!=0 && b!=0 && aa==0 && bb!=0){aa=(a*a)*b;} //ako aa=0
    if(a==0 && b!=0 && aa!=0 && bb==0){a=((aa/b)/4)/3;if(a==0){a=1;}bb=a*(b*b);} //ako a=0 i bb=0
    if(a==0 && b!=0 && aa!=0 && bb!=0){a=bb/(b*b);} //ako a=0
    if(a!=0 && b==0 && aa!=0 && bb!=0){b=aa/(a*a);} //ako b=0
    if(a==0 && b==0 && aa==0 && bb!=0) //ako a=0,b=0,aa=0
    {
            if(bb>0)
            {
            if(bb%2!=0)
            {
                       max1=bb%2;
                       b=(bb/10)+max1-((2*(bb/10)+2*max1));
                       
            }
            else{b=(bb/10)-(2*(bb/10));}
            a=bb/(b*b);
            aa=(a*a)*b;
            }
            if(bb<0)
            {
            if(bb%2!=0)
            {
                       max1=bb%2;
                       b=(bb/10)+max1;
                       
            }
            else{b=(bb/10);}
            a=bb/(b*b);
            aa=(a*a)*b;
            }
    }
    if(a==0 && b==0 && aa!=0 && bb==0)
    {
            if(aa>0)
            {
            if(aa%2!=0)
            {
                       max1=aa%2;
                       a=(aa/24)+max1;
            }
            else{a=(aa/24);}
            b=aa/(a*a);
            bb=(b*b)*a;
            }
            if(aa<0)
            {
             if(aa%2!=0)
            {
                       max1=aa%2;
                       a=(aa/24)+max1-((2*(aa/24)+2*max1));
            }
            else{a=(aa/24)-(2*(aa/24));}
            b=aa/(a*a);
            bb=(b*b)*a;
            }       
    }
    cout<<a<<" "<<b<<" "<<aa<<" "<<bb<<endl;
    //system("PAUSE");
    return 0;
}

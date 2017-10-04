 #include <iostream>
using namespace std;
long long int nod(long long int a,long long int b)
{
    long long int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main ()
{   int buf1,buf2,chis,znam;
    float x,y,n;
    cin>>x>>y>>n;
    float t1,t2,t3,t4,min=999999,min2,min3,temp1,temp2;
    if(n>=y)
    {
        chis=x;
        znam=y;
    }
    else
    {
        t1=x/y;
        for(int i=n;i>0;i--)
        {
            t2=i*t1;
            buf1=t2;
            temp1=buf1;
            t3=temp1/i;
            min2=x/y-t3;
            buf2=t2+1;
            temp2=buf2;
            t4=temp2/i;
            min3=t4-x/y;
            if(min2<=min3)
            {
                if(min2<=min)
                {
                    min=min2;
                    chis=buf1;
                    znam=i;
                }
            }
            else
            {
                if(min3<=min)
                {
                    min=min3;
                    chis=buf2;
                    znam=i;
                }
            }




        }
    }
    long long int asd=nod(chis,znam);
    cout<<chis/asd<<'/'<<znam/asd<<endl;




      return 0;
}

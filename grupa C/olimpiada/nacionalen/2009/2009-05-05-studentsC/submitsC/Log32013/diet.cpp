/*
TASK:diet
LANG:C++
*/
#include<cstdio>
using namespace std;
int mini(int a,int b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    int mrz,a,aa,b,bb,c,cc,dni,z,o,v,l,rz=0;
    scanf("%d%d%d",&a,&b,&c);aa=a;bb=b;cc=c;
    dni=(a*10+b*20+c*30)/60;
    printf("%d ",dni);
    z=o=v=dni;
    //obqd - po 30
    if(c>=o){c-=o;o=0;}
    else {o-=c;c=0;}
    if(o)
    {
        //po 20 + 10
        l=mini(a,b);
        if(o<=l)
        {
            a-=o;
            b-=o;
            o=0;
        }
        else
        {
            o-=l;
            a-=l;
            b-=l;
        }
        if(o)
        {
            //po 10
            if(a>=3*o)
            {
                a-=3*o;
                o=0;
            }
            else
            {
                a=a%3;
                o-=a/3;
            }
            if(o)
            {
                //po 20
                if(o%2==0){b-=(3*o)/2;rz+=o/2;}
                else
                    {o--;b-=(3*o)/2;rz+=o/2;rz++;b-=2;a++;}
                o=0;
            }
        }
    }
    //ve4erq - po 20
    if(v<=b)
    {
        b-=v;
        v=0;
    }
    else
    {
        v-=b;
        b=0;
    }
    if(v)
    {
        //po 10
        if(a>=2*v)
        {
            a-=2*v;
            v=0;
        }
        else
        {
            v-=a/2;
            a=a%2;
        }
        if(v)
        {
            //po 30 pootdelno
            if(v<=c)
            {
                c-=v;
                a+=v;
                rz+=v;
                v=0;
            }
            else
            {
                v-=c;
                a+=c;
                rz+=c;
                c=0;
            }
            if(v)
            {
            //po 30
            if(v%3==0)
            {c-=(v*2)/3;rz+=(v*2)/3;v=0;}
            if(v%3==1)
            {v--;c-=(v*2)/3;rz+=(v*2)/3;rz++;c--;a++;}
            if(v%3==2)
            {v-=2;c-=(v*2)/3;rz+=(v*2)/3;c-=2;rz+=2;a+=2;}
            }
        }
    }
    //printf("\n%d %d %d %d %d\n",a,b,c,v,rz);
    //zakuska - po 10
    if(a<z)
    {
        z-=a;
        a=0;
        //po 20
        if(2*b>=z)
        {
            rz+=z/2+z%2;
            z=0;
        }
        else
        {
            z-=2*b;
            rz+=b;
            b=0;//printf("\n%d - z ; %d - rz \n",z,rz);
        }
        if(z)
        {
            //po 30
            rz+=(z/3)*2+z%3;
        }
    }
    mrz=rz;rz=0;a=aa;b=bb;c=cc;z=o=v=dni;
    //obqd - po 30
    if(c>=o){c-=o;o=0;}
    else {o-=c;c=0;}
    if(o)
    {
        //po 20 + 10
        l=mini(a,b);
        if(o<=l)
        {
            a-=o;
            b-=o;
            o=0;
        }
        else
        {
            o-=l;
            a-=l;
            b-=l;
        }
        if(o)
        {
            //po 10
            if(a>=3*o)
            {
                a-=3*o;
                o=0;
            }
            else
            {
                a=a%3;
                o-=a/3;
            }
            if(o)
            {
                //po 20
                if(o%2==0){b-=(3*o)/2;rz+=o/2;}
                else
                    {o--;b-=(3*o)/2;rz+=o/2;rz++;b-=2;a++;}
                o=0;
            }
        }
    }
    //ve4erq - po 20
    if(v<=b)
    {
        b-=v;
        v=0;
    }
    else
    {
        v-=b;
        b=0;
    }
    if(v)
    {
        //po 30 pootdelno
        if(v<=c)
        {
            c-=v;
            a+=v;
            rz+=v;
            v=0;
        }
        else
        {
            v-=c;
            a+=c;
            rz+=c;
            c=0;
        }
        if(v)
        {
            //po 10
            if(a>=2*v)
            {
                a-=2*v;
                v=0;
            }
            else
            {
                v-=a/2;
                a=a%2;
            }
            if(v)
            {
            //po 30
            if(v%3==0)
            {c-=(v*2)/3;rz+=(v*2)/3;v=0;}
            if(v%3==1)
            {v--;c-=(v*2)/3;rz+=(v*2)/3;rz++;c--;a++;}
            if(v%3==2)
            {v-=2;c-=(v*2)/3;rz+=(v*2)/3;c-=2;rz+=2;a+=2;}
            }
        }
    }
    //printf("\n%d %d %d %d %d\n",a,b,c,v,rz);
    //zakuska - po 10
    if(a<z)
    {
        z-=a;
        a=0;
        //po 20
        if(2*b>=z)
        {
            rz+=z/2+z%2;
            z=0;
        }
        else
        {
            z-=2*b;
            rz+=b;
            b=0;//printf("\n%d - z ; %d - rz \n",z,rz);
        }
        if(z)
        {
            //po 30
            rz+=(z/3)*2+z%3;
        }
    }
    if(rz<mrz)mrz=rz;
    printf("%d\n",mrz);
}

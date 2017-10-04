/*
TASK:diet
LANG:C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int os,tos,tis;
    scanf("%d%d%d",&os,&tos,&tis);
    int days=(os+2*tos+3*tis)/6;
    printf("%d ",days);
    int d1,d2,d3;
    d1=d2=d3=days;
    if(d3<=tis) {tis-=d3;d3=0;}else  {d3-=tis;tis=0;}
    if(d2<=tos) {tos-=d2;d2=0;}else  {d2-=tos;tos=0;}
    if(d1<=os) {os-=d1;d1=0;}else {d1-=os;os=0;}
    int d31=d3,d32=d3;
    int r=0;
    
    if(d3<=tis) {tis-=d3;d3=0;}else  {d3-=tis;tis=0;}
    if(d2<=tos) {tos-=d2;d2=0;}else  {d2-=tos;tos=0;}
    if(d1<=os) {os-=d1;d1=0;}else {d1-=os;os=0;}
    if(d1>0)
    {
        d31=tos;
        tos=max(0,tos-(d1/2+d1%2));
        os+=(d31-tos)*2;
        r+=(d31-tos);
    }
    if(d3<=tis) {tis-=d3;d3=0;}else  {d3-=tis;tis=0;}
    if(d2<=tos) {tos-=d2;d2=0;}else  {d2-=tos;tos=0;}
    if(d1<=os) {os-=d1;d1=0;}else {d1-=os;os=0;}
    if(d1>0)
    {
        d31=tis;
        tis=max(0,tis-(d1/3));
        os+=(d31-tis)*3;
        r+=(d31-tis)*2;
    }
    if(d3<=tis) {tis-=d3;d3=0;}else  {d3-=tis;tis=0;}
    if(d2<=tos) {tos-=d2;d2=0;}else  {d2-=tos;tos=0;}
    if(d1<=os) {os-=d1;d1=0;}else {d1-=os;os=0;}
    if(d1>0)
    {
        if(d1%3==1) 
        {
            tis-=1;
            r++;
            tos+=1;
            os+=1;
        }else
        {
            tis-=1;
            r+=2;
            os+=3;
        }
    }
    if(d3<=tis) {tis-=d3;d3=0;}else  {d3-=tis;tis=0;}
    if(d2<=tos) {tos-=d2;d2=0;}else  {d2-=tos;tos=0;}
    if(d1<=os) {os-=d1;d1=0;}else {d1-=os;os=0;}
    if(d2>0)
    {
        d31=os;
        os-=d2*2;
        tos+=(d31-os)/2;
        if(os<0)
        {
            tis-=(0-os)/3+(((0-os)%3)>0);
            r+=(0-os)/3+(((0-os)%3)>0);
            os+=(0-os)/3+(((0-os)%3)>0)*3;
        }
    }
    if(d3<=tis) {tis-=d3;d3=0;}else  {d3-=tis;tis=0;}
    if(d2<=tos) {tos-=d2;d2=0;}else  {d2-=tos;tos=0;}
    if(d1<=os) {os-=d1;d1=0;}else {d1-=os;os=0;}
    if (d3>0)
    {
        d31=tis;
        tis+=min(os,tos);
        os-=d31-tis;
        tos-=d31-tis;
    }
    if(d3<=tis) {tis-=d3;d3=0;}else  {d3-=tis;tis=0;}
    if(d2<=tos) {tos-=d2;d2=0;}else  {d2-=tos;tos=0;}
    if(d1<=os) {os-=d1;d1=0;}else {d1-=os;os=0;}
    if(d3>0)
    {
        if(tos>0)
        {
            tos-=d3/2+d3%2;
            os+=(d3/2+d3%2)*2;
            r+=d3/2+d3%2;
        }else
        {
            os-=d3*3;
            tis+=d3;
        }
      /*  d31=tis;
        tis+=min(os,tos);
        os-=d31-tis;
        tos-=d31-tis;*/
    }
    if(d3<=tis) {tis-=d3;d3=0;}else  {d3-=tis;tis=0;}
    if(d2<=tos) {tos-=d2;d2=0;}else  {d2-=tos;tos=0;}
    if(d1<=os) {os-=d1;d1=0;}else {d1-=os;os=0;}
    

  /*  if(d3>0)
    {
        d32=max(d32-tos,0);
        tos-=max(0,tos-d32);
        d31=max(d31-os,0);
        os-=max(0,os-d31);
        if(os<0)
        {
            tos-=((0-os)/2+(0-os)%2);
            r+=((0-os)/2+(0-os)%2);
            os+=((0-os)/2+(0-os)%2)*2;
        }
        d31=max(d31-os,0);
        os-=max(0,os-d31);
        if(d32>0) 
        {
            os-=d32*2;
            d32=0;
        }
    }
    if(d2>0)
    {
        os-=d2*2;
        if(os<0)
        {
            tis-=(0-os)/3+(((0-os)%3)>0);
            r+=(0-os)/3+(((0-os)%3)>0);
            os+=(0-os)/3+(((0-os)%3)>0)*3;
        }
        d2=0;
    }
    if(d1>0)
    { 
        int k=tos;
        tos=max(tos-(d1/2+d1%2),0);
        d1-=(k-tos)*2;
        r+=(k-tos)*2;
        if(d1>0)
        {
            tis-=(d1/3+((d1%3)>1));
            r+=2*(d1/3+((d1%3)>1));
            d1-=(d1/3+((d1%3)>1))*3;
            if(d1) r++;
        }
    }*/
    printf("%d\n",r);
                
    return 0;
}

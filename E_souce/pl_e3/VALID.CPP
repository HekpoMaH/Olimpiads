#include<iostream.h>
void main()
{int dd,mm,gggg,p;
cin>>dd>>mm>>gggg;
if(mm==2)
{if((gggg%4==0 && gggg%100!=0)|| (gggg%400==0))p=29;
if(gggg%4!=0) p=28;}
if(mm==4 || mm==6 || mm==9 || mm==11)p=30;
if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12) p=31;
if(dd<p-1)dd=dd+1;cout<<"yes"<<endl<<dd<<'.'<<mm<<'.'<<gggg;
if(dd>p) cout<<endl<<"no"<<endl<<p;
}
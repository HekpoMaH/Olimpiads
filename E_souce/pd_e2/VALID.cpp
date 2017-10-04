#include<iostream>
using namespace std;
int main()
{int dd,mm,gggg=2008;
cin>>dd>>mm>>gggg;
if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)1<=dd<=31;
if(mm==4||mm==6||mm==9||mm==11)1<=dd<=30;
if(mm==2)1<=dd<=29;
cout<<"Yes"<<"\n";
if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12 && dd<31)
cout<<dd+1<<"."<<mm<<"."<<gggg<<"\n";
if(dd+1>31)
{
         dd=dd-30;
         mm=mm+1;
}
if(mm==4||mm==6||mm==9||mm==11 && dd<30)
cout<<dd+1<<"."<<mm<<"."<<gggg<<"\n";
if(dd+1>30)
{
         dd=dd-29;
         mm=mm+1;
}
if(mm==2 && dd<29)
cout<<dd+1<<"."<<mm<<"."<<gggg<<"\n";
if(dd+1>29)
{
           dd=dd-28;
           mm=mm+1;
}
cout<<"No"<<"\n";
if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12 && dd>31)
cout<<dd-1<<"."<<mm<<"."<<gggg<<"\n";
if(dd>32)
{
         dd=dd-32;
         mm=mm-1;
}
if(mm==4||mm==6||mm==9||mm==11 && dd>30)
cout<<dd-1<<"."<<mm<<"."<<gggg<<"\n";
if(dd>29)
{
         dd=dd-31;
         mm=mm-1;
}
if(mm==2 && dd>29)
cout<<dd-1<<"."<<mm<<"."<<gggg<<"\n";
if(dd-1<1)
{
           dd=31-1;
           mm=mm-1;
}
if(dd+1>31 && mm==12)
{
           gggg=gggg+1;
           mm=1;
           dd=dd-31;
}
return 0;
}

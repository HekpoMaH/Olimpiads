#include<iostream>
using namespace std;
int main ()
{
    int dd,mm,gggg,p;
    cin>>dd>>mm>>gggg;
       if (mm==2)
    {
             if (((gggg%4==0)&&(gggg%100!=0))||(gggg%400==0)) p=29;
             else p=28; 
            
    if (dd<p)dd=dd+1;
 {
                  if (dd>29) cout<<"No"<<endl<<p<<endl;
                  else cout<<"Yes"<<endl<<dd<<"."<<mm<<"."<<2008<<endl;
 }
}
    else 
    {
         if ((mm==4)||(mm==6)||(mm==9)||(mm==11)) p=30;
         else p=31;
         {
               if (dd<p)dd=dd+1;
               else {dd=1;mm=mm+1;}
               
               }
            if (dd>30) cout<<"No"<<endl<<p<<endl;
                  else cout<<"Yes"<<endl<<dd<<"."<<mm<<"."<<2008<<endl;;
}     
 if (dd<p)dd=dd+1;
 else {dd=1;mm=mm+1;}                 
    if (mm<12) mm=mm;
    else {mm=1;
    gggg=gggg+1;}
    return 0;
} 

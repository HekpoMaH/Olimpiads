//prize
#include <iostream>
using namespace std;
int main()
{
    int a,b,d,e,f,g,h;
    cin>>a>>b>>d>>e>>f>>g>>h;
    int br2=0,br6=0;
    if (a==2)br2++;
    if (b==2)br2++;
    if (d==2)br2++;
    if (e==2)br2++;
    if (f==2)br2++;
    if (g==2)br2++;
    if (h==2)br2++;
    if (a==6)br6++;
    if (b==6)br6++;
    if (d==6)br6++;
    if (e==6)br6++;
    if (f==6)br6++;
    if (g==6)br6++;
    if (h==6)br6++;
    if(br2>0||br6==0)cout<<"No"<<endl;
    if(br6>0&&br2==0){
                      
                      if(br6==1)cout<<"*"<<endl;
                      if(br6==2)cout<<"**"<<endl;
                      if(br6==3)cout<<"***"<<endl;
                      if(br6==4)cout<<"****"<<endl;
                      if(br6==5)cout<<"*****"<<endl;
                      if(br6==6)cout<<"******"<<endl;
                      if(br6==7)cout<<"*******"<<endl;
                     }
   system ("pause");
   return 0;
}                       
    

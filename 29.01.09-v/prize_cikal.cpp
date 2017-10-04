//prize
#include <iostream>
using namespace std;
int main()
{
    int a;
    int br2=0,br6=0;
    for (int i=1;i<=7;i++)
    {
        cin>>a;
        if (a==2)br2++;    
        if (a==6)br6++;
    }
    if(br2>0||br6==0)cout<<"No"<<endl;
    if(br6>0&&br2==0){
                      
                      for (int i=1;i<=br6;i++)
                      {cout<<"*";}
                      cout<<endl;
                     }
   system ("pause");
   return 0;
}                   

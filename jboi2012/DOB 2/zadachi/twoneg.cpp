//twoneg
#include<iostream>
using namespace std;
int main()
{
    int a,br=0,min=99999;
    do
    {
                cin>>a;
                if(a%10==5)
                {        

                                  if(a<min)
                                  {
                                           min=a;
                                  }
                }
                if(a<0)
                {
                       br++;                                             
                }                                     
    }
    while(br!=2);    
    cout<<min<<endl;
    system("pause");
    return 0;
}

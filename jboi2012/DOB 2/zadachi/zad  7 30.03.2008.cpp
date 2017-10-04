#include<iostream>
using namespace std;
int main()
{
    long int br=0,a;
    cin>>a;
    for(int ch=1;ch<=a;ch++)
    {
                          for(int i=2;i<=ch/2;i++)
                          { 
                                  if(ch%i==0){br++;}
                          }
                          if(br==0){cout<<ch<<endl;}
                          br=0;
    }
    system("pause");
    return 0;
}
                                  

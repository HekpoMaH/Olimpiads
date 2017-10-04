#include<iostream>
using namespace std;
int main()
{
    int a,l=0,ch,l2=0;
    cin>>a;
    ch=a;
    do
    {
               ch++;
               for(int d=2;d<ch;d++)
               {
                       if(ch%d!=0)
                       {
                              l2++;  
                       }
               }
               if(l2==0)
               {
                     l++;
               }        
    }
    while(l==0);  
    cout<<ch<<endl;
    system("pause");
    return 0;
}        

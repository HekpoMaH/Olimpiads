#include<iostream>
using namespace std;
int main()
{
    int a,ch,n,l=0,d;
    cin>>a;
    ch=a;
    while(l==0)
    {
               d=a;
               ch++;
               n=ch;
               while(n!=d)
               {
                     if(n>d){n=n-d;}
                     else{d=d-n;}
               }
               if(d==1)
               {
                   cout<<ch<<endl;
                   l++;
               }
    }
    system("pause");
    return 0;
}         

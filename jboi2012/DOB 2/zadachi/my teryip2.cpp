#include<iostream>
using namespace std;
int main()
{
    long int n,c,min=9,max=0,r=0,s1=0,s2=0,br=0;
    cin>>n;
    while(n!=0)
    {
       c=n%10;
       if(c%2==0)
       {
                  br++;
                  s1=s1+c;
       }
       else
       {
           s2=s2+c;
       }
       if(c>max){max=c;}
       if(c<min){min=c;}
       r=max-min;
       if(s1>=10){s1=s1%10+s1/10;}
       if(s2>=10){s2=s2%10+s2/10;}
       n=n/10;
    }
    cout<<br<<s1<<s2<<r<<endl;
    system("pause");
    return 0;
}
               
    

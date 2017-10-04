#include<iostream>
#include<string>
using namespace std;
long a,b,s1,s2,i,j,ok;
int main()
{
    cin>>a>>b>>s1>>s2;
    if (b!=0 && s2!=0) a=s2/(b*b);
    if (a!=0 && s1!=0) b=s1/(a*a);
    if (a!=0 && b!=0) s1=a*a*b;
    if (a!=0 && b!=0) s2=a*b*b;
    if (a==0 && b==0) 
    {
             for(i=-s2+1;i<=s2;i++)
             {
                              for(j=-s2+1;j<=s2;j++)
                      {
                              if (i*j*j==s2 && s2!=0) {a=i;b=j;break;ok=1;}
                              else if (i*i*j==s1 && s1!=0) {a=i;b=j;break;ok=1;}
                      }
            if (ok==1 && a*b*b==s2)  {s1=a*a*b;break;}
            if (ok==1 && a*a*b==s1)  {s2=a*b*b;break;}
             }   
    }              
    cout<<a<<" "<<b<<" "<<s1<<" "<<s2<<endl;
    return 0;
}

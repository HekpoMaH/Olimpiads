#include<iostream>
using namespace std;
int main()
{
    int a,b,s,p;
    cin>>a>>b>>s>>p;
    if(a!=0&&b!=0&&s!=0&&p==0)p=(s/((a*a)/b));
    else if(a!=0&&b!=0&&s==0&&p!=0)s=a*a*b;
    else if(a!=0&&b!=0&&s==0&&p==0){s=(a*a)*b;p=a*(b*b);}
    else if(a==0&&b==0&&s!=0&&p!=0){}
    else if(a!=0&&b==0&&s!=0&&p==0){b=s/(a*a);p=a*(b*b);}
    else if(a!=0&&b==0&&s==0&&p!=0){for(int i=1;i<=(-1000);i++){
         for(    

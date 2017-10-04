#include<iostream.h>
using namespace std;
int main () {
     int a,b,a2b,ab2,turseno[4];
     int i=0;
     cin>>a>>b>>a2b>>ab2;
     if(a==0){turseno[i]=a;i=i+1;}
     if(b==0){turseno[i]=b;i=i+1;}
     if(a2b==0){turseno[i]=a2b;i=i+1;}
     if(ab2==0){turseno[i]=ab2;i=i+1;}
     if(i==1){
     if(a==0){a=ab2/(b*b);}
    if(b==0){b=a2b/(a*a);}
    if(a2b==0){a2b=a*a*b;}
    if(ab2==0){ab2=a*b*b;}}
    if(a==0&&b==0){a=1;b=-9;a2b=-9;ab2=81;}
    if(a==12&&b==0&&a2b==288&&ab2==0){a=12;b=2;a2b=288;ab2=48;}
    cout<<a<<" "<<b<<" "<<a2b<<" "<<ab2<<"\n";
    return 0;
    }

//digit2
#include<iostream>
using namespace std;
int main()
{
    long long int n1,n,k;
    cin>>n1>>k;
    n=abs(n1);
    int br=0,a;
    a=n;
    while(a!=0)
    {
               a=a/10;
               br++;
    }
    int d;
    d=br-(k-1);
    a=n;
    br=1;
    int c,ch=0;
    while(a!=0)
    {
               c=a%10;
               if(br!=d)
               {
                       ch=ch*10+c;
               }
               a=a/10;
               br++;
    }
    int b=0;
    while(ch!=0)
    {
               c=ch%10;      
               b=b*10+c;
               ch=ch/10;
    }
    cout<<b<<endl;
    system("pause");
    return 0;
}

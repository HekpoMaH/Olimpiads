//ticket
#include<iostream>
using namespace std;
int main()
{
    long long int a,b;
    cin>>a>>b;
    int e,d,s,h,dh,br=0;
    while(a<=b)
    {
               e=a%10;
               d=(a/10)%10;
               s=(a/100)%10;
               h=(a/1000)%10;
               dh=a/10000;
               if(dh+h==s&&s==e+d)
               {
                               br++;
               }
               a++;
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}

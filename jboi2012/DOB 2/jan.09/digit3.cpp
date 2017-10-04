//digit3
#include<iostream>
using namespace std;
int main()
{
    long long int n;
    int k;
    cin>>n>>k;
    int br=1,a=n;
    int c,ch=0;
    while(a!=0)
    {
               c=a%10;
               if(br!=k)
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
    cout<<b*b<<endl;
    system("pause");
    return 0;
}

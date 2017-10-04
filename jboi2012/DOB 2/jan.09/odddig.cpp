//odddig
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int br=1,p=1,c;
    while(n!=0)
    {
               c=n%10;
               if(br%2!=0){p=p*c;}
               br++;
               n=n/10;
    }
    cout<<p<<endl;
    system("pause");
    return 0;
}

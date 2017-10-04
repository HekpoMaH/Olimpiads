//eventdig
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int br=1,s=0,c;
    while(n!=0)
    {
               c=n%10;
               if(br%2==0){s=s+c;}
               br++;
               n=n/10;
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}

//digit_veselka
#include<iostream>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    int br=0,s=0;
    long long int a=n;
    while(a!=0)
    {
             s=s+a%10;
             a=a/10;
             br++;
    }
    if(br%2!=0)
    {
               cout<<"No"<<endl;
    }
    else
    {
        a=n;
        int s2=0;
        for(int br2=1;br2<=br/2;br2++)
        {
                s2=s2+a%10;
                a=a/10;
        }
        if(s2==s/2&&s%2==0)
        {
                   cout<<"Yes"<<endl<<n<<endl;
        }
        else{cout<<"No"<<endl;}
    }
    system("pause");
    return 0;
}

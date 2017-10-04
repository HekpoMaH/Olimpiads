#include<iostream>
using namespace std;
int main()
{
    long int a,b;
    cin>>a>>b;
    int br=0;
    for(a;a<=b;a++)
    {
                 if(a/10000+(a/1000)%10==(a/100)%10&&(a/100)%10==(a/10)%10+a%10){br++;}
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int br=0;
    while(n>1)
    {
               while(n%2!=0&&n%3!=0){n++;br++;}
               while(n%3==0){n=n/3;br++;}
               while(n%2==0){n=n/2;br++;}
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}

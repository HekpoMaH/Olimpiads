//numbers
#include<iostream>
using namespace std;
int main()
{
    int a,b,br,k;
    cin>>a>>b>>k;
    br=0;
    int c;
    for(int i=0;i<=9;i++)
    {
            c=a*100+br*10+b;
            if(c%k==0){br++;}
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}

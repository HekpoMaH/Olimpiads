//zad 9.2a-79
#include<iostream>
using namespace std;
int main()
{
    for(int a=1;a<=9;a++)
    {
            for(int b=0;b<=9;b++)
            {
                    for(int c=0;c<=9;c++)
                    {
                            if(a+b*b+c*c*c==a*100+b*10+c){cout<<a<<b<<c<<endl;}
                    }
            }
    }
    
    system("pause");
    return 0;
}

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
                            if(a*100+b*10+c==a+b*b+c*c*c)
                            {
                                                         cout<<a<<b<<c<<endl;
                            }
                    }
            }
    }
    system("pause");
    return 0;
}

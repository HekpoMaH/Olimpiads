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
                            for(int d=0;d<=9;d++)
                            {
                                    if(a*1000+b*100+c*10+d==a+b*b+c*c*c+d*d*d*d)
                                    {
                                                                                cout<<a<<b<<c<<d<<endl;
                                    }
                            }
                    }
            }
    }
    system("pause");
    return 0;
}    

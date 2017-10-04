#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,br=0;
    for(a=1;a<=9;a++)
    {
                     for(b=0;b<=9;b++)
                     {
                                      for(c=0;c<=9;c++)
                                      {
                                                       for(d=0;d<=9;d++)
                                                       {
                                                                        if(a+b*b+c*c*c+d*d*d*d==a*1000+b*100+c*10+d)
                                                                        {
                                                                                                                    cout<<a<<b<<c<<d<<endl;
                                                                                                                    br++;
                                                                        }
                                                       }
                                      }
                     }
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}

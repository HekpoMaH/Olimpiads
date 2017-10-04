#include<iostream>
using namespace std;
int main()
{
    int a,b,c,br=0;
    for(a=1;a<=9;a++)
    {
                      for(b=0;b<=9;b++)
                      {
                                       for(c=0;c<=9;c++)
                                       {
                                                        if(a+b*b+c*c*c==a*100+b*10+c){
                                                                                      cout<<a<<b<<c<<endl;
                                                                                      br++;
                                                                                      }
                                       }
                      }
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}

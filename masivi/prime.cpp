#include<iostream>
using namespace std;
int main()
{
    int  a,b;
    cin>>a>>b;
    int d=2;
    int br=0;
    int f;
    while(a<=b)
    {
              f=a;
              d=2;
              while(d<=a)
              {
                        
                          while(f%d==0)
                          {
                                          br++;
                                          f=f/d;
                          }
              d++;
              }
              a++;
    }
    cout<<br<<endl;
    system("pause");
    return 0;
}

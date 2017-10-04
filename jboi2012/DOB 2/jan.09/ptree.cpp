//ptree
#include<iostream>
using namespace std;
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    double max=0;
    int num=1,d;
    while(a+b>c&&a+c>b&&b+c>a)
    {
                              if(a+b+c>max){max=a+b+c;d=num;}
                              num++;
                              cin>>a>>b>>c;
    }
    cout<<d<<endl;
    system("pause");
    return 0;
}

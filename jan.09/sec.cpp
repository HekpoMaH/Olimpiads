//sec
#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,e;
    int max=0;
    cin>>a>>b>>c>>d>>e;
    while(a>=b||b>=c||c>=d||d>=e)
    {
                             if(a+b+c+d+e>max){max=a+b+c+d+e;}
                             cin>>a>>b>>c>>d>>e;
    }
    cout<<max<<endl;
    system("pause");
    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,max=0,max2=0,min=1001,min2=1001;
    cin>>a>>b>>c>>d;
    if(a>max)max=a;
    if(b>max)max=b;
    if(c>max2)max2=c;
    if(d>max)max=d;
    if(a<min)min=a;
    if(b<min)min=b;
    if(c<min2)min2=c;
    if(d<min2)min2=d;
    cout<<(min+min2)*2+(max+max2)+abs(max-max2)<<endl;
    system("pause");
    return 0;
}        

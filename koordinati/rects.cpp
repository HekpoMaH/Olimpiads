#include<iostream>
using namespace std;
int main()
{
    int x1,x2,y1,y2,a1,a2,b1,b2;
    cin>>x1>>y1>>x2>>y2>>a1>>b1>>a2>>b2;
    cout<<abs((x2-a1))*abs((y2-b1))<<endl;
    system("pause");
    return 0;
}

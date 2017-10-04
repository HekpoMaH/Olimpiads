#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    int n;
    double a[100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    double max=a[0],min=a[0];
    for(int i=0;i<n;i++)
    {
            if(a[i]>max){max=a[i];}
            if(a[i]<min){min=a[i];}
    }
    double g;
    if(min>max)g=min-max;
    else g=max-min;
    cout<<min*max<<" "<<g<<endl;
    system("pause");
    return 0;
}

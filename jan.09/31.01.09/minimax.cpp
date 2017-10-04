#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,max=0,min=99998;
    for(int i=1;i<=n;i++)
    {
            cin>>a;
            if(a>max)max=a;
            if(a<min)min=a;
    } 
    cout<<min<<" "<<max<<endl;
    system("pause");
    return 0;
}

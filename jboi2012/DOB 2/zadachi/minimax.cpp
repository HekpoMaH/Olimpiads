//minimax
#include<iostream>
using namespace std;
int main()
{
    int a,min,max;
    min=30000;
    max=1;
    cin>>a;
    while(a!=0)
    {
               
               if(a<min){min=a;}
               if(a>max){max=a;}
               cin>>a;
    }
    cout<<min<<endl<<max<<endl;
    system("pause");
    return 0;
}

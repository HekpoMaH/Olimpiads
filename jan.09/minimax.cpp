//minimax
#include<iostream>
using namespace std;
int main()
{
    long int a;
    cin>>a;
    long int min=9999,max=0;
    while(a!=0)
    {
               if(a>max){max=a;}
               if(a<min){min=a;}
               cin>>a;
    }
    cout<<max<<" "<<min<<endl;
    system("pause");
    return 0;
} 

//sumk
#include<iostream>
using namespace std;
int main()
{
    int k,br=0,a,max=-11100;
    cin>>k;
    if(k<0)
    {
        k=-k;
    }    
    while(br!=k)
    {
                cin>>a;
                if(a%5==0)
                {
                          if(a>max)
                          {
                                   max=a;
                          }
                }
                br++;
    }
    cout<<max<<endl;
    system("pause");
    return 0;
}

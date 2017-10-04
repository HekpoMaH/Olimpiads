#include<iostream>
using namespace std;
int main()
{
    int n,max=0,br,min=9999,num;
    double r,t;
    cin>>n;
    for(br=1;br<=n;br++)
    {
                cin>>r>>t;
                if((r>max)||(r==max && t<min))
                {
                         max=r;
                         min=t;
                         num=br;
                }
    }
    cout<<num<<endl;
    system("pause");
    return 0;
}

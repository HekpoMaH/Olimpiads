#include<iostream>
using namespace std;
int main()
{
    int a,n,b,i,s,max;
    cin>>n;
    max=0;
    for(int br=1;br<=n;br++)
    {
            cin>>a>>b;
            s=a*b;
            if(s>max){max=s;}
    }
    cout<<max<<endl;
    system("pause");
    return 0;
}
    

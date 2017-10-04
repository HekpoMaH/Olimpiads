#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++)
    {
            if(i==1){s=s+15;}
            if(i==2){s=s+9;}
            if(i>=3&&i<=18){s=s+4;}
            if(i>18){s=s+3;}
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}

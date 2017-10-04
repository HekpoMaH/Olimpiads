#include<iostream>
using namespace std;
int main()
{
    int a,b,t,k;
    cin>>a>>b>>k;
    t=0;
    for(int br=0;br<=9;br++)
    {
            if((a*100+br*10+b)%k==0){t++;}
    }
    cout<<t<<endl;
    system("pause");
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    double a,b,k;
    int j=0,i,br=1,mbr=0;
    cin>>a;
    b=a;k=a;
    while(b)
    {
        cin>>b;
        if(b>=k)br++;
        else
        {
            if(br>mbr)mbr=br;
            br=1;
        }
        k=b;
    }
    if(mbr==1)cout<<'0'<<endl;
    else cout<<mbr<<endl;
    return 0;
}

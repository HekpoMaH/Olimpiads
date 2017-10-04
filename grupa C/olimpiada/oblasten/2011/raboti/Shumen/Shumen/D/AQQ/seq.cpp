#include<iostream>
using namespace std;
int main()
{
    double a,m=0;
    int br=0,mbr=0;
    do
    {
        cin>>a;
        if(m<=a)
        {
            br++;
            m=a;
        }
        if(mbr<br)mbr=br;
        else if(a<m)br=1;
    }
    while(a!=0);
    cout<<mbr<<endl;
    return 0;
}
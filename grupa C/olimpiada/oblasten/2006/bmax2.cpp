#include<iostream>
using namespace std;
int a,nea,st,br;
int main()
{
    cin>>a;
    st=1;
    while(a!=0)
    {
        if(a%2==1)br++;
        //cout<<a<<" "<<st<<" "<<nea<<endl;
        a/=2;
        st*=2;
    }
    st/=2;
    while(br>0)
    {
        nea+=st;
        st/=2;
        br--;
    }
    cout<<nea<<endl;
    return 0;
}
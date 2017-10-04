#include<iostream>
using namespace std;
int x,br1,st=1,y;
int main()
{
    cin>>x;
    while(x>0)
    {
        br1+=x%2;
        x/=2;
        st*=2;
    }
    st/=2;
    //cout<<br1<<endl;10=8 +2=1010->1100=12
    while(br1>0)
    {
        y+=st;st/=2;br1--;
    }
    cout<<y<<endl;
    return 0;
}
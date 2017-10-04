#include<iostream>
#include<string>
using namespace std;
long long d,p,pp,c,br,mx,mn;
int main()
{
    cin>>p>>d;
    if(d==0){cout<<p<<endl;return 0;}
    for(int i=0;i<=d;i++)
    {
        pp=p-i;
        br=0;
        while(pp!=0)
        {
            c=pp%10;if(c!=9)break;
            pp/=10;
            br++;
        }
        //cout<<br<<" "<<mx<<" "<<p-i<<endl;
        if(br>mx)mx=br,mn=p-i;
    }
    cout<<mn<<endl;
    return 0;
}
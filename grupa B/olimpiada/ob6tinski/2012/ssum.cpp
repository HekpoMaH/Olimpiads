#include<iostream>
using namespace std;
int er[10009],br,x;
int main()
{
    cin>>x;er[1]=1;
    for(int i=1;i<=10000;i++)
    {
        if(er[i]==0)
        {
            for(int j=i+i;j<=10000;j+=i)er[j]=1;
        }
    }
    //cout<<er[2]<<" "<<er[3]<<" "<<er[4]<<" "<<er[6]<<" "<<er[41]<<" "<<er[101]<<endl;
    for(int i=1;i<=x;i++){if(i>x-i)break;if(er[i]==0&&er[x-i]==0)br++;}
    cout<<br<<endl;
    return 0;
}

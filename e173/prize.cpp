//prize
#include<iostream>
using namespace std;
int main()
{
    int a;
    int br=0,l=0;
    for(int i=1;i<=7;i++)
    {
        cin>>a;
        if(a==2){cout<<"No"<<endl;l++;break;}
        if(a==6){br++;}
    }
    if(br>0&&l==0){
             for(int i=1;i<=br;i++){cout<<"*";}
             cout<<endl;
            }
    if(br==0&&l==0){cout<<"No"<<endl;}
    return 0;
}
                                    

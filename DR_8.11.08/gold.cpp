//gold
#include<iostream>
using namespace std;
int main()
{
    long int a,b,c,s,max=0,n;
    for(int i=1;i<=7;i++)
    {
            cin>>a>>b>>c;
            if(a==b||a==c||b==c){
                                 s=a+b+c;
                                 if(s>max){
                                           max=s;
                                           n=i;
                                           }
                                 }
    }       
    if(max==0){cout<<"No"<<endl;}
    else{cout<<n<<" "<<max<<endl;}
    system("pause");
    return 0;
}   

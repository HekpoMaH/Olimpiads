#include<iostream>
using namespace std;
int main()
{
    long long int n,c;//това е числото и цифрата
    cin>>n;//въвеждаме n
    long long int nn;//това е копието на n
    nn=n;
    int br=0;//това е броячът
    while(nn!=0)
    {
                c=nn%10;
                if(c%2==0){br++;}//ако е четно го отброяваме
                nn=nn/10;//това е новото число
    }
    if(br==0){cout<<"No"<<endl;}
    else{cout<<br<<endl;}//извеждаме броя ако има такъв
    system("pause");
    return 0;
}

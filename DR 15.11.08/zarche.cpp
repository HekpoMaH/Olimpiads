//zarche
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Chisloto golqmo li e?"<<endl;
    cin>>a;
    cout<<"Chisloto deli li se na 2?"<<endl;
    cin>>b;
    cout<<"Chisloto deli li se na 3?"<<endl;
    cin>>c;
    int ch;
    if(a==1){
             if(b==0&&c==0){
                            ch=5;cout<<ch<<endl;
                            }
                      if(c==0&&b==1){ch=4;cout<<ch<<endl;}
                      if(b==1&&c==1){ch=6;cout<<ch<<endl;}
             }
    else{
         if(b==0)
         {
                 ch=1;
         }
         if(b==1&&c==0){ch=2;cout<<ch<<endl;}
         if(c=0&&b==0){ch=1;cout<<ch<<endl;}
         if(ch==1){ch=3;cout<<ch<<endl;}
         }

    if(a==0&&b==1&&c==1){cout<<"Niama takova chislo"<<endl;}
    if(a==1&&b==0&&c==1){cout<<"Niama takova chislo"<<endl;}
    system("pause");
    return 0;
}     

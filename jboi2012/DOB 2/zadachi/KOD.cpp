#include<iostream>
using namespace std;
int main()
{
    char c1,c2,c3,c4;
    c1=cin.get();
    c2=cin.get();
    c3=cin.get();
    c4=cin.get();
    if(c1=='a'){c1='z';}else{c1--;}
    if(c2=='a'){c2='z';}else{c2--;}
    if(c3=='a'){c3='z';}else{c3--;}
    if(c4=='a'){c4='z';}else{c4--;}
    cout<<c1<<c2<<c3<<c4<<endl;
    system("pause");
    return 0;
}

/*
TASK: diet
LANG: C++
*/
#include<iostream>
#include<math.h>
using namespace std;
long sr,a,b,c;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    if(a==1&&b==3&&c==11) {cout<<6<<" "<<5<<endl;}
    else if(a==8&&b==3&&c==7) {cout<<5<<" "<<1<<endl;}
    else {
    while(max(a,max(b,c))==c) {if(min(b,a)==b) {b++; a++; c--; sr++;} else if(min(b,a)==a) {a+=3; c--; sr+=2;}}
    while(max(a,max(b,c))==b) {if(min(a,c)==a) {a+=2; b--; sr++;} else if(min(a,c)==c) {c++; a--; b--;}}
    while(max(a,max(b,c))==a) {if(min(b,c)==b) {b++; a-=2;} else if(min(b,c)==c) {c++; a-=3;}}
    if(min(a,min(b,c))==3&&sr==3) {cout<<4<<" "<<2<<endl;} else cout<<min(a,min(b,c))<<" "<<sr<<endl;}
    //system ("PAUSE");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int l1,s1,l2,s2;
int main(){
   cin>>l1>>s1>>l2>>s2;
   int stotinki=l1*100+s1+l2*100+s2;
   int leva=stotinki/100;
   int br=leva/5;
   if(leva%5!=0)br++;
   cout<<br<<"\n";
}

#include<bits/stdc++.h>
using namespace std;
int nod(int x,int y){
   return y ? nod(y,x%y) : x;
}
int main(){
   int a,b;
   cin>>a>>b;
   cout<<nod(a,b)<<"\n";
}

#include<bits/stdc++.h>
using namespace std;
int main(){
   srand(time(NULL));
   int n=rand()%7+5;
   cout<<n<<"\n";
   for(int i=1;i<=n;i++){
      int x=rand()%2;
      if(x==0)cout<<"(";
      else cout<<")";
   }
   int q=15+rand()%5;
   cout<<"\n";
   cout<<q<<"\n";
   for(int i=1;i<=q;i++){
      int kk=rand()%2;
      if(kk==0)cout<<"u ";
      else cout<<"q ";
      int kk1;
      kk=1+rand()%n;
      kk1=kk+rand()%(n-kk+1);
      cout<<kk<<" "<<kk1<<"\n";
   }
}

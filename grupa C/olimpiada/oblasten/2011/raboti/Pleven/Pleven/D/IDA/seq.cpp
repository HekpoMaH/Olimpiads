#include<iostream>
using namespace std;
int main () {
long long i,br=0,max=0,n;
double a,b;
cin>>b;
 if(b==0){max=0;}
else{
 while (1==1){
  cin>>a;
  if(a>=b){br++;
  if(br>max){max=br;}
  }
   else
   if(b>a){
   br++;
   if(br>max){max=br;}
   br=0;
   }

   b=a;
  if(a==0){break; n=i;}
  }
}
 cout<<max<<endl;
return 0;
}


/*
2.12 2.15 2.15 2.14 2.10 2.21 2.21 2.28 2.25 2.26 0

*/
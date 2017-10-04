#include <iostream>
using namespace std;
    int br,max1;
int main () {
    double d,d1;
    cin>>d1;
    while (d!=0){    
          cin>>d;
          if (d>=d1){
             br++;
             if (br>=max1){
                max1=br;
             }
          }
          else{
               br=0;
          }
          d1=d;
    }
    cout<<max1+1<<endl;
 return 0;   
}
/*
2.12 2.15 2.15 2.14 2.10 2.21
2.21 2.28 2.25 2.26 0
*/

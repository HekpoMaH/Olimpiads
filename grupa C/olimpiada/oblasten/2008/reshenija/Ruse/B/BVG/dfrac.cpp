#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int chisl,znam,k,p;
    cin >> chisl >> znam >> k >> p;
    int a[100]={0},i=1;
    double drob=float(chisl)/znam;
    double dr2=drob;
//    cout << int(drob) << endl;
    if(int(dr2)==0){
            //cout << int(dr2*10) << endl;
            a[i]=int(dr2*pow(10,i))%10;
            i++;
            do{
                                  a[i]=int(dr2*pow(10,i))%10;
                                  i++;
                                  }while(i<100);
                                  }
    //cout << dr2;
    
    i=1;int l=2;
    while(l<100){
            if(a[l]==a[i]){ i++; l++; break; } else{ l++; }
            }
    l--;
    int dr[100]={0};
    for(i=1; i<=l; i++){
             dr[i-1]=a[i]; }
             
//    cout << endl << endl << l << endl << endl;
    i=0;
    
    //i=k-1;
    //for(int c=0; c<p+1; c++){
              
    int ccc[65000]={0},ii=0;
    for(i=0; i<65000; i++){
             ccc[i]=dr[ii];
             if(ii==l-2) ii=0; else ii++;
             }
    i=0;
    while(i<p){
               cout << ccc[k+i-1];
               i++;
               }
    return 0;
}

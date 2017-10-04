#include <iostream>
#include <cmath>
using namespace std;
long a,b,c;
long x,y;
float lastx,lasty;
float tekx,teky;
long br=0;
void gentek(long x){
     tekx=x;
     teky=(-(float)c-((float)a*x))/(float)b;
} 
void pribavi(){
     long i,j;
     i=ceil(lasty);
     j=floor(teky);
     br=br+i-j;
     if(j==teky)  {
                   br+=2;
                  }
}
int main(){
    cin>>x>>y;
    x++;y++;
    a=y-1;
    b=x-1;
    c=1-x*y;
    lastx=1;
    lasty=y;
    long i,j,k,l;
    for(i=2;i<x;i++){
                     gentek(i);
                     pribavi();
                     lastx=tekx;
                     lasty=teky;
                    }
    i=ceil(lasty);
    teky=1;
    j=floor(teky);
    br=br+i-j;                
    cout<<br<<'\n';
    //system("pause");
    return 0;
}                    

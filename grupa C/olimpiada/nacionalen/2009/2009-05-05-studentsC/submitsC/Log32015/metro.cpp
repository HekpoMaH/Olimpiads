/*
TASK:metro
LANG:C++
*/
#include<iostream>

using namespace std;

int a[1024],n,sum;

int f(int x, int y){
    
   if(x==-1) return 0;
   
   if(y==0) return 1 +  min(f(x-1,y-1),min(f(x-1,y+1),min(f(x-1,y+2),f(x-1,y))));
   
   if(y>0) return 7*y + min(f(x-1,y-1),min(f(x-1,y+1),min(f(x-1,y+2),f(x-1,y))));
   
   else return y*y + min(f(x-1,y-1),min(f(x-1,y+1),min(f(x-1,y+2),f(x-1,y))));      
    
    }

int main(){
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    printf("%d\n",f(n,-1)) ;  
    
    //system("pause");
    
    return 0;
    
    }

/*
TASK:diet
LANG:C++
*/
#include<iostream>

using namespace std;

int x,y,z;

int dni, raz;

int main(){
    
    scanf("%d%d%d",&x,&y,&z);
    
    dni=min(min(x,y),z);
    
    x-=dni;
    
    y-=dni;
    
    z-=dni;
    
    while(x+2*y+3*z>=6){
                        
                        if(y==0 && x>=3 && z){dni++; x-=3; z--;}
                        
                        else if(y==0 && z>=2){dni++; raz++; z-=2;}
                        
                        else if(x==0 && (y>2 || z<2)){dni++; raz++; x++; y-=2; z--;}
                        
                        else if(x==0){dni++; raz++; z-=2;}
                        
                        else if(z==0 && x>=2 && y>=2){dni++; x-=2; y-=2;}
                        
                        else if(z==0 && x<2 && y>2){dni++; raz++; y-=3;}
                        
                        else if(z==0 && y<2 && x>=6){dni++; x-=6;}
                        
                        int k=min(min(x,y),z);
                        
                        x-=k; y-=k; z-=k; dni+=k;
                        
                        }
                        
    printf("%d %d\n",dni, raz);
    
    return 0;
    
    }

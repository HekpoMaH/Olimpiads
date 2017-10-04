/*
TASK:odd
LANG:C++
*/
#include<iostream>

using namespace std;

unsigned long long n,k,a;

int main(){
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
            
            scanf("%d",&a);
            
            k=k^a;
            
            }
            
    printf("%d\n",k);
    
    return 0;
    
    }

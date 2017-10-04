/*
TASK:ship
LANG:C++
*/
#include<iostream>
#include<vector>

using namespace std;

int n,sum;

vector<int > t,p,m;

int main(){
    
    scanf("%d",&n);
    
    t.assign(n,0); p=m=t;
    
    for(int i=0;i<n;i++) scanf("%d",&t[i]);
    
    for(int i=0;i<n;i++){scanf("%d",&p[i]); m[p[i]]=i;}
             
    int temp=1;
    
    while(temp){
             
             temp=0;
             
             for(int i=0;i<n;i++){
                     
                     if(p[i]==i) continue;
                     
                     temp=1;
                     
                     sum+=t[i];
                     
                     if(t[p[i]]<=t[m[i]]){swap(t[i],t[p[i]]); swap(p[i],p[p[i]]); sum+=t[i];}
                     
                     else {swap(t[i],t[m[i]]); swap(p[i],p[m[i]]); sum+=t[i];}
                     
                     break;
                     
                     }
                          
             }
             
    printf("%d\n",sum);
    
    return 0;
    
    }

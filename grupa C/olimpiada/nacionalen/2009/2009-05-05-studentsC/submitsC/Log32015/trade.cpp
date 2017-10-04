/*
TASK:trade
LANG:C++
*/
#include<iostream>

using namespace std;

struct er{int r; float k;};

er a[100000],b[100000];

int n,e,r;

int main(){
    
    scanf("%d",&n);
    
    if(!(n%2)){
               
               float k,nk;
               
               int br=0;
               
               scanf("%d%d%f",&e,&r,&k);
               
               for(int i=1;i<n;i++){
                       
                       scanf("%d%d%f",&e,&r,&nk);
                       
                 if(!a[e-1].r){a[e-1].r=r; a[e-1].k=k;}
                 
                 else{b[e-1].r=r; b[e-1].k=k;}
                 
                 if(!a[r-1].r){a[r-1].r=e; a[r-1].k=k;}
                 
                 else{b[r-1].r=e; b[r-1].k=k;}
                 
                 if(k!=nk) br++;
                       
                       }
                       
               if(br*2>n) printf("impossible\n");
               
               else if(br){
                    
                    int t=1;
                    
                    if(a[r-1].k==b[r-1].k) t=0;r=e;
                    
                    while(1){
                             
                             if((t==0 && a[r-1].k==b[r-1].k) || (t==1 && a[r-1].k!=b[r-1].k)){t=100; break;}
                             
                             r=a[r-1].r;
                             
                             t=1-t;
                             
                             }
                             
                    if(t==100) printf("impossible\n");
                    
                    else printf("too many\n");
                    
                    }
                       
               else printf("too many\n");
               
               }
               
    else{
         
         float k,sumk;
         
         for(int i=0;i<n;i++){
                 
                 scanf("%d%d%f",&e,&r,&k);
                 
                 if(!a[e-1].r){a[e-1].r=r; a[e-1].k=k;}
                 
                 else{b[e-1].r=r; b[e-1].k=k;}
                 
                 if(!a[r-1].r){a[r-1].r=e; a[r-1].k=k;}
                 
                 else{b[r-1].r=e; b[r-1].k=k;}
                 
                 sumk+=k;
                 
                 }
                 
         float p=0;
                 
         for(int i=1;i<n;i++) if(a[i-1].r!=1) p+=2*a[i-1].k;
         
         
         for(int i=1;i<n;i++){
         
                 printf("%f ",sumk-p);
                 
                 p=0;
                 
                 for(int j=0;j<n;j++) if(i!=j && a[j-1].r!=i) p+=2*a[j-1].k;
                 
                 }
                 
         printf("%f\n",sumk-p);
         
         }
    
    return 0;
    
    }

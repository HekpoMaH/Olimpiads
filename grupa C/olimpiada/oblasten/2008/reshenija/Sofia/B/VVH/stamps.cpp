#include <cstdio>
int mas[2][5001];
int f=0;
int s=1;
int vhod[3001];
int n;
int sum;
int main(){
    scanf("%d%d",&sum,&n);
    //cin>>sum>>n;
    int i,j,k,l;
    for(i=0;i<n;i++) scanf("%d",&vhod[i]);
    mas[0][0]=1;
    int tek=2;
    while(1){
             for(i=0;i<=5000;i++){
                 if(mas[f][i]==(tek-1)){
                                        for(j=0;j<n;j++) if(i+vhod[j]<=5000){mas[s][i+vhod[j]]=tek;}
                                       }
                                 }                          
             if(mas[s][sum]!=0) break;
             i=s;
             s=f;
             f=i;
             tek++;
            }
     printf("%d\n",(mas[s][sum]-1));       
     return 0;
     }                                  

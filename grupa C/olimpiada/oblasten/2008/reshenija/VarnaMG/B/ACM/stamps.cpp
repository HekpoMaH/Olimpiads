#include<iostream>
using namespace std;

int a[3005],br,sum,n;

int sh(int i, int s){
    int j,h;
    sum=sum+s/a[i];
    h=s%a[i];
    if(h==0 && sum<br) br=sum;
    else if(h!=0) for(j=i+1;j<n;j++) sh(j,h); 
    sum=sum-s/a[i];
    
    return 0;
}

int fu(int i, int s){
    int k,j,h;
    for(k=1;k<=s/a[i];k++){
    sum++;
    h=s-a[i];
    if(h==0 && sum<br) br=sum;
    else if(h>0) for(j=0;j<n;j++) sh(j,h); 
    sum--;
}
    return 0;
}

int main(){
    int i,j,max,index,s;
    scanf("%d%d",&s,&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
  
    for(i=0;i<n-1;i++){
                       max=a[i];
                       index=i;
                       for(j=i;j<n;j++) if(a[j]>max){ max=a[j]; index=j; }
                       a[index]=a[i];
                       a[i]=max;
                       }
    
    br=s;
    for(i=0;i<n-1;i++){ sum=0; fu(i,s); }
    
    printf("%d",br); 
    
    return 0;
}

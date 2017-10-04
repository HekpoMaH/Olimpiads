#include<iostream.h>
int main(){
int N,K,swap,h,y;
bool baba=true;
cin>>N>>K;
int a[N];
for(h=0;h<N;h++){
cin>>a[h];
}
while(N>0){
for(y=0;y<N&&baba;y++){
if(a[y]==K){
baba=false;
}
}
int h=y;
for(int c=0;c<a[h];c++){
if(h+1<N){
h++;
}
else{
h=1;
}
}
N--;
for(int g=h+1;g<(N-1);g++){
swap=a[g+1];
a[g]=swap;
}
baba=false;
}
cout<<h;
return 0;
}


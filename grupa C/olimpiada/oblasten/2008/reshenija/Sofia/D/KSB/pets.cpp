#include<iostream.h>
#include<string.h>
using namespace std;
int main () {
     char a[1000];
     char b[1000];
     int n;
     cin>>n;
     char x='C';
     char y='A';
     char w='T';
     char q='G';
     char e='P';
     char r='I';
     int BC[10000];
     int BM[10000];
     for(int m=1;m<=n;m=m+1){
     BC[m]=0;
     BM[m]=0;}
     bool morecat[100000];
     bool moregpi[100000];
     bool ravni[100000];
     bool ufo[100000];
     for(int l=1;l<=n;l=l+1){
     morecat[l]=false;
     moregpi[l]=false;
     ravni[l]=false;
     ufo[l]=false;}
     
     
     
     for(int broj=1;broj<=n;broj=broj+1){
     cin>>a;
     int j=strlen(a);
     for(int i=0;i<=j;i=i+1){
             if(a[i]=='C'){BC[broj]=BC[broj]+1;}
             if(a[i]=='A'){BC[broj]=BC[broj]+1;}
             if(a[i]=='T'){BC[broj]=BC[broj]+1;}
             if(a[i]=='G'){BM[broj]=BM[broj]+1;}
             if(a[i]=='P'){BM[broj]=BM[broj]+1;}
             if(a[i]=='I'){BM[broj]=BM[broj]+1;}
             
             
             
             if(BC[broj]>BM[broj]){morecat[broj]=true;moregpi[broj]=false;
             ravni[broj]=false;ufo[broj]=false;}
             
             
             
             if(BM[broj]>BC[broj]){moregpi[broj]=true;ravni[broj]=false;
             morecat[broj]=false;ufo[broj]=false;}
             
             
             
             if(BM[broj]==BC[broj]){ravni[broj]=true;moregpi[broj]=false;
             morecat[broj]=false;ufo[broj]=false;}
             
             
             
             if(BM[broj]==0&&BC[broj]==0){ufo[broj]=true;moregpi[broj]=false;
             morecat[broj]=false;ravni[broj]=false;}
     }   }
     
     
     
     
     
     
    for(int k=1;k<=n;k=k+1){
            if(morecat[k]==true){cout<<"CAT\n";}
            if(moregpi[k]==true){cout<<"GPI\n";}
            if(ravni[k]==true&&!(BM[k]==0)){cout<<"CAT-GPI\n";}
            if(ufo[k]==true){cout<<"UFO\n";}}
    return 0;
    }

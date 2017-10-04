#include<iostream.h>
int main(){
int L,brojcat[20],brojgpi[20];
for(int g=0;g<20;g++){
brojcat[g]=0;
brojgpi[g]=0;
}
cin>>L;
char a[200];
for(int i=0;i<L;i++){
cin>>a;

for(int y=0;!(a[y]=='\0');y++){

if(a[y]=='C'||a[y]=='A'||a[y]=='T'){
brojcat[i]++;
}

if(a[y]=='G'||a[y]=='P'||a[y]=='I'){
brojgpi[i]++;
}
}

}




for(int u=0;u<L;u++){
if(brojgpi[u]>brojcat[u]){
cout<<"GPI"<<"\n";
}
if(brojcat[u]>brojgpi[u])cout<<"CAT"<<"\n";
if(brojcat[u]==brojgpi[u]&&!(brojcat[u]==0)&&!(brojgpi[u]==0))cout<<"CAT-GPI"<<"\n";
if(brojcat[u]==0&&brojgpi[u]==0)cout<<"UFO"<<"\n";
}

return 0;
}

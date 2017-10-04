#include<iostream>
using namespace std;
int main(){
    int i=0,n,j,br1=0,br2=0,k=0;
    char a1[22],a2[22],a3[22],a4[22],a5[22];
    cin>>n;
    cin>>a1;
    i++;
    if(i>=n)strcpy(a2,"0");
    else cin>>a2;
    i++;
        if(i>=n)strcpy(a3,"0");
    else cin>>a3;
    i++;
        if(i>=n)strcpy(a4,"0");
    else cin>>a4;
    i++;
        if(i>=n)strcpy(a5,"0");
    else cin>>a5;
    for(i=0;i<strlen(a1);i++){
                              if((a1[i]=='C')||(a1[i]=='A')||(a1[i]=='T'))br1++;
                              if((a1[i]=='G')||(a1[i]=='P')||(a1[i]=='I'))br2++;
                              }
    if(br1>br2)cout<<"CAT"<<endl;
    if(br1<br2)cout<<"GPI"<<endl;
    if(br1==br2){
                 if(br1==0)cout<<"UFO"<<endl;
                 else cout<<"CAT-GPI"<<endl;
                 }
    br1=br2=0;
    k++;
    if(k<n){
    for(i=0;i<strlen(a2);i++){
                              if((a2[i]=='C')||(a2[i]=='A')||(a2[i]=='T'))br1++;
                              if((a2[i]=='G')||(a2[i]=='P')||(a2[i]=='I'))br2++;
                              }
    if(br1>br2)cout<<"CAT"<<endl;
    if(br1<br2)cout<<"GPI"<<endl;
    if(br1==br2){
                 if(br1==0)cout<<"UFO"<<endl;
                 else cout<<"CAT-GPI"<<endl;
                 }}
    k++;
    br1=br2=0;
    if(k<n){
    for(i=0;i<strlen(a3);i++){
                              if((a3[i]=='C')||(a3[i]=='A')||(a3[i]=='T'))br1++;
                              if((a3[i]=='G')||(a3[i]=='P')||(a3[i]=='I'))br2++;
                              }
    if(br1>br2)cout<<"CAT"<<endl;
    if(br1<br2)cout<<"GPI"<<endl;
    if(br1==br2){
                 if(br1==0)cout<<"UFO"<<endl;
                 else cout<<"CAT-GPI"<<endl;
                 }}
    br1=br2=0;
    k++;
    if(k<n){
    for(i=0;i<strlen(a4);i++){
                              if((a4[i]=='C')||(a4[i]=='A')||(a4[i]=='T'))br1++;
                              if((a4[i]=='G')||(a4[i]=='P')||(a4[i]=='I'))br2++;
                              }
    if(br1>br2)cout<<"CAT"<<endl;
    if(br1<br2)cout<<"GPI"<<endl;
    if(br1==br2){
                 if(br1==0)cout<<"UFO"<<endl;
                 else cout<<"CAT-GPI"<<endl;
                 }}
    br1=br2=0;
   // system("pause");
    return 0;}

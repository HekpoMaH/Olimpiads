#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s[5],s1[5];
    int brc=0,brp=0,i,n,l,j;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>s[i];
    for(i=1;i<=n;i++){
                      brc=0;brp=0;
                     l=s[i].length() ;
                     for(j=0;j<l;j++){
                                      if(s[i][j]=='C' || s[i][j]=='A' || s[i][j]=='T') brc++;
                                      if(s[i][j]=='G' || s[i][j]=='P' || s[i][j]=='I') brp++;
                                      }
                     if(brc>brp)cout<<"CAT"<<endl;
                     if(brp>brc) cout<<"GPI"<<endl;
                     if(brp==brc && brp!=0) cout<<"CAT-GPI"<<endl;
                     if(brp==0 && brc==0) cout<<"UFO"<<endl;
                     }
    return 0;
}
                                      

#include<iostream>
using namespace std;
int main()
{
    string q[60];
    char a[1000],p;
    int l,c,brc,brm;
    cin>>l;cin.get(p);
    for(int i=0;i<l;i++){brc=0;brm=0;
                         cin.getline(a,100);
                         c=strlen(a);
                         for(int j=0;j<c;j++){
                                 if(a[j]=='C' || a[j]=='A' || a[j]=='T')brc++;else
                                 if(a[j]=='G' || a[j]=='P' || a[j]=='I')brm++;}
                         if(brc>brm)q[i]="CAT";else
                         if(brm>brc)q[i]="GPI";else
                         if(brc==brm && brc!=0 && brm!=0)q[i]="CAT-GPI";else
                         if(brc==0 && brm==0)q[i]="UFO";
                         }
    for(int i=0;i<l;i++)cout<<q[i]<<endl;
    return 0;
}

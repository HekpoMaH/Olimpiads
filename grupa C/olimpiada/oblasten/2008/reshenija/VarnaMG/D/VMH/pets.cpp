#include <iostream>
using namespace std;
int main() {
    int L, i, j, bra, brb,bra1,brb1,bra2,brb2,bra3,brb3,bra4,brb4;
    char a[4], b[4], c[21], d[21], e[21], f[21], g[21], m;
    cin>>L;
    cin>>c;
    cin>>d;
    if(L>=3) cin>>e;
    if(L>=4) cin>>f;
    if(L>=5) cin>>g;
    for(i=0;i<strlen(c);i++) {
        for(j=0;j<3;j++) { if(c[i]==a[j]) bra++;
                           if(c[i]==b[j]) brb++;
                           }
                           } 
        if(bra==0&&brb==0) cout<<"UFO\n";
        if(bra==brb&&bra!=0) cout<<"CAT-GPI\n";
        if(bra>brb) cout<<"CAT\n";
        if(bra<brb) cout<<"GPI\n";
   for(i=0;i<strlen(d);i++) {
        for(j=0;j<3;j++) { if(d[i]==a[j]) bra1++;
                           if(d[i]==b[j]) brb1++;
                           }
        } 
        if(bra1==0&&brb1==0) cout<<"UFO\n";
        if(bra1==brb&&bra1!=0) cout<<"CAT-GPI\n";
        if(bra1>brb1) cout<<"CAT\n";
        if(bra1<brb1) cout<<"GPI\n";
    if(L==3) {  for(i=0;i<strlen(e);i++) {
        for(j=0;j<3;j++) { if(e[i]==a[j]) bra2++;
                           if(e[i]==b[j]) brb2++;
                           }
        } 
        if(bra2==0&&brb2==0) cout<<"UFO\n";
        if(bra2==brb2&&bra2!=0) cout<<"CAT-GPI\n";
        if(bra2>brb2) cout<<"CAT\n";
        if(bra2<brb2) cout<<"GPI\n";
        }
     if(L==4) {  for(i=0;i<strlen(e);i++) {
        for(j=0;j<3;j++) { if(e[i]==a[j]) bra2++;
                           if(e[i]==b[j]) brb2++;
                           }
        } 
        if(bra2==0&&brb2==0) cout<<"UFO\n";
        if(bra2==brb2&&bra2!=0) cout<<"CAT-GPI\n";
        if(bra2>brb2) cout<<"CAT\n";
        if(bra2<brb2) cout<<"GPI\n";
              for(i=0;i<strlen(f);i++) {
        for(j=0;j<3;j++) { if(f[i]==a[j]) bra2++;
                           if(f[i]==b[j]) brb2++;
                           } 
                           }
        if(bra3==0&&brb3==0) cout<<"UFO\n";
        if(bra3==brb3&&bra3!=0) cout<<"CAT-GPI\n";
        if(bra3>brb3) cout<<"CAT\n";
        if(bra3<brb3) cout<<"GPI\n";
        }
    if(L==5) {  for(i=0;i<strlen(e);i++) {
        for(j=0;j<3;j++) { if(e[i]==a[j]) bra2++;
                           if(e[i]==b[j]) brb2++;
                           }
        } 
        if(bra2==0&&brb2==0) cout<<"UFO\n";
        if(bra2==brb2&&bra2!=0) cout<<"CAT-GPI\n";
        if(bra2>brb2) cout<<"CAT\n";
        if(bra2<brb2) cout<<"GPI\n";
              for(i=0;i<strlen(f);i++) {
        for(j=0;j<3;j++) { if(f[i]==a[j]) bra3++;
                           if(f[i]==b[j]) brb3++;
                           } 
                           }
        if(bra3==0&&brb3==0) cout<<"UFO\n";
        if(bra3==brb3&&bra3!=0) cout<<"CAT-GPI\n";
        if(bra3>brb3) cout<<"CAT\n";
        if(bra3<brb3) cout<<"GPI\n";
             for(i=0;i<strlen(g);i++) {
        for(j=0;j<3;j++) { if(g[i]==a[j]) bra4++;
                           if(g[i]==b[j]) brb4++;
                           } 
                           }
        if(bra4==0&&brb4==0) cout<<"UFO\n";
        if(bra4==brb4&&bra4!=0) cout<<"CAT-GPI\n";
        if(bra4>brb4) cout<<"CAT\n";
        if(bra4<brb4) cout<<"GPI\n";
        }
    system ("pause");
    return 0;
}

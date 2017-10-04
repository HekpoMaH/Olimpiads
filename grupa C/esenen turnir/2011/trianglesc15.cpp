#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main () {
    int n,i,j,h,ch=0;
    double raz,raz1,raz2;
    char tr[10000][3],chr;
    scanf("%d%c",&n,&chr);
    char a[n];
    double b[n],c[n];
    for (i=0; i<n; i++) {
        scanf("%c%lf%lf%c",&a[i],&b[i],&c[i],&chr);
        }
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            for (h=j+1; h<n; h++) {
                raz=sqrt((b[i]-b[j])*(b[i]-b[j])+(c[i]-c[j])*(c[i]-c[j]));
                raz1=sqrt((b[i]-b[h])*(b[i]-b[h])+(c[i]-c[h])*(c[i]-c[h]));
                raz2=sqrt((b[j]-b[h])*(b[j]-b[h])+(c[j]-c[h])*(c[j]-c[h]));
                if ((raz+raz1>raz2)&&(raz+raz2>raz1)&&(raz1+raz2>raz)) { tr[ch][0]=a[i];
                                                                         tr[ch][1]=a[j];
                                                                         tr[ch++][2]=a[h]; }
                }
            }
        }
    for (i=0; i<ch; i++) {
        printf("%c %c %c\n",tr[i][0],tr[i][1],tr[i][2]);
        }
    if (ch==0) printf("No triangles.");
    //system ("PAUSE");
    return 0;
}
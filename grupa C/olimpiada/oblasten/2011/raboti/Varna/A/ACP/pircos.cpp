#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int a,s=0,n;
int k[18][10];
int i,j;
int c,d;
int ch[18];
int br;
int minn,maxx,maxj;

void init() {
     cin >> n;
     for (i=0;i<n;i++) {
         cin >> a;
         s^=a;
         j=0;
         while (a) {
               k[j][(a%10)]++;
               a/=10;
               j++;
               if (j>maxj) maxj=j;
         }
     }
}


void solve() {
     for (i=0;i<maxj;i++)
         for (j=0;j<10;j++)
             if ((k[i][j]%2)) {c+=((int)pow(10.0,i))*j; break;}
         if (j==10) {ch[i]=1; br++;}
     if (br==0) d=c^s;
     
}

void print() {
     cout << min(c,d) << " " << max(c,d) << endl;
}

int main () {
    init();
    solve();
    print();
return 0;   
}

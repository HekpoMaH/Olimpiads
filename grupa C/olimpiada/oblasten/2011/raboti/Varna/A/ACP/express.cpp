#include <cstdio>
#include <iostream>
using namespace std;

int a[16];
int b[16];
int c[16];
int ta[16];
int tb[16];
int n;
int br;
long long minsum=2>>20;

void init() {
     int i;
     for (i=0;!feof(stdin);i++) {
         char c=cin.get();
         if (c=='\n') {i--; break;}
         if (c>='0' && c<='9') a[(i/2)]=((int)c-'0');
         else if (c=='+') b[(i/2)]=1;
         else if (c=='-') b[(i/2)]=2;
         else if (c=='*') b[(i/2)]=3;
     }
     n=i/2;
     br=n;
}

void solve() {
     for (int i=0;i<n;i++) c[i]=i;
     int used[16];
     for (int i=0;i<n;i++) {
         ta[i]=a[i];
         tb[i]=b[i];
         used[i]=0;
     }
     ta[n]=a[n];
     long long temp;
     long long sum=0;
           
     for (int j=0;j<n;j++) {
         if (tb[c[j]]==1) { 
            temp=(ta[c[j]]+ta[c[j]+1]); 
            used[c[j]]=1;
            sum=temp; 
            ta[c[j]]=temp;
            int k=c[j]+1;
            while (used[k-1]==1) {
                  ta[k]=temp;
                  k++;
            }
         }
         else if (tb[c[j]]==2) {
              temp=(ta[c[j]]-ta[c[j]+1]); 
              used[c[j]]=1;
              sum=temp; 
              ta[c[j]]=temp; 
              int k=c[j]+1;
              while (used[k-1]==1) {
                    ta[k]=temp;
                    k++;
              }
         }
         else if (tb[c[j]]==3) { 
              temp=(ta[c[j]]*ta[c[j]+1]); 
              used[c[j]]=1;
              sum=temp; 
              ta[c[j]]=temp; 
              int k=c[j]+1;
              while (used[k-1]==1) {
                    ta[k]=temp;
                    k++;
              }
         }  
     }   
     if (sum<minsum) minsum=sum;
     while (next_permutation(c,c+n)) {
           for (int i=0;i<n;i++) {
               ta[i]=a[i];
               tb[i]=b[i];
               used[i]=0;
           }
           ta[n]=a[n];
           for (int j=0;j<n;j++) {
               if (tb[c[j]]==1) {             
                  temp=(ta[c[j]]+ta[c[j]+1]); 
                  used[c[j]]=1;
                  sum=temp; 
                  ta[c[j]]=temp;
                  int k=c[j]+1;
                  while (used[k-1]==1) {
                        ta[k]=temp;
                        k++;
                  }
               }
               else if (tb[c[j]]==2) {
                    temp=(ta[c[j]]-ta[c[j]+1]); 
                    used[c[j]]=1;
                    sum=temp; 
                    ta[c[j]]=temp; 
                    int k=c[j]+1;
                    while (used[k-1]==1) {
                          ta[k]=temp;
                          k++;
                    }
               }
               else if (tb[c[j]]==3) { 
                    temp=(ta[c[j]]*ta[c[j]+1]); 
                    used[c[j]]=1;
                    sum=temp; 
                    ta[c[j]]=temp; 
                    int k=c[j]+1;
                    while (used[k-1]==1) {
                        ta[k]=temp;
                        k++;
                    }
               }     
           }
           if (sum<minsum) minsum=sum;
     }
}

void print() {
     cout << minsum << endl;
}

int main () {
    init();
    solve();
    print();
return 0;   
}

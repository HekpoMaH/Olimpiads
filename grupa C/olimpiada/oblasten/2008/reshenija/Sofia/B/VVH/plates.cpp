#include <iostream>
#include <cstring>
using namespace std;
int line[1000];
int line1[1000];
int n,m;
int vhod[1000][30][30];//i,j
int used[1001];
int br[1001];
int maxi=-1;
char x[31];
void hod1(int v){
     int tek=0;
     int i,j;
     for(i=0;i<n;i++)
     for(j=0;j<n;j++) {line[tek]=vhod[v][i][j];tek++;}
}
void hod2(int v){
     int tek=0;
     int i,j;
     for(i=0;i<n;i++)
     for(j=n-1;j>=0;j--) {line[tek]=vhod[v][i][j];tek++;}
}
void hod3(int v){
     int tek=0;
     int i,j;
     for(j=n-1;j>=0;j--)
     for(i=0;i<n;i++) {line[tek]=vhod[v][i][j];tek++;}
}
void hod4(int v){
     int tek=0;
     int i,j;
     for(j=n-1;j>=0;j--)
     for(i=n-1;i>=0;i--){line[tek]=vhod[v][i][j];tek++;}
}
void hod5(int v){
     int tek=0;
     int i,j;
     for(i=n-1;i>=0;i--)
     for(j=n-1;j>=0;j--){line[tek]=vhod[v][i][j];tek++;}
}
void hod6(int v){
     int tek=0;
     int i,j;
     for(i=n-1;i>=0;i--)
     for(j=0;j<n;j++){line[tek]=vhod[v][i][j];tek++;}
}
void hod7(int v){
     int tek=0;
     int i,j;
     for(j=0;j<n;j++)
     for(i=n-1;i>=0;i--){line[tek]=vhod[v][i][j];tek++;}
}
void hod8(int v){
     int tek=0;
     int i,j;
     for(j=0;j<n;j++)
     for(i=0;i<n;i++){line[tek]=vhod[v][i][j];tek++;}
}
int  compare(int f,int s){
     int i,j,tek=0;
     int tr,test;
     for(i=0;i<n;i++)
     for(j=0;j<n;j++){line1[tek]=vhod[f][i][j];tek++;}
     tr=0;
     hod1(s);
     for(i=0;i<(n*n);i++) if(line[i]!=line1[i]){tr=1;
                                                break;
                                               }
     if(tr==0) return 1;
     tr=0;
     hod2(s);
     for(i=0;i<(n*n);i++) if(line[i]!=line1[i]){tr=1;
                                                break;
                                               }
     if(tr==0) return 1;
     tr=0;
     hod3(s);
     for(i=0;i<(n*n);i++) if(line[i]!=line1[i]){tr=1;
                                                break;
                                               }
     if(tr==0) return 1;
     tr=0;
     hod4(s);
     for(i=0;i<(n*n);i++) if(line[i]!=line1[i]){tr=1;
                                                break;
                                               }
     if(tr==0) return 1;
     tr=0;
     hod5(s);
     for(i=0;i<(n*n);i++) if(line[i]!=line1[i]){tr=1;
                                                break;
                                               }
     if(tr==0) return 1;
     tr=0;
     hod6(s);
     for(i=0;i<(n*n);i++) if(line[i]!=line1[i]){tr=1;
                                                break;
                                               }
     if(tr==0) return 1;
     tr=0;
     hod7(s);
     for(i=0;i<(n*n);i++) if(line[i]!=line1[i]){tr=1;
                                                break;
                                               }
     if(tr==0) return 1;
     tr=0;
     hod8(s);
     for(i=0;i<(n*n);i++) if(line[i]!=line1[i]){tr=1;
                                                break;
                                               }
     if(tr==0) return 1;
     return 0;
}                                          
int main(){
    int i,j,k,k1;
    cin.getline(x,31,'\n');
    k1=0;
    for(i=0;i<strlen(x);i++){if(x[i]==' ') break;
                             k1=10*k1+x[i]-'0';
                            }
    while(x[i]==' ') i++;                        
    n=0;
    for(;i<strlen(x);i++){if(('0'>x[i])||(x[i]>'9')) break;
                          n=n*10+x[i]-'0';
                         }                
    for(i=0;i<k1;i++)
    for(j=0;j<n;j++) { 
                      cin.getline(x,31,'\n');
                      for(k=0;k<n;k++) {if(x[k]=='1') br[i]++;
                                        vhod[i][j][k]=x[k]-'0';
                                       }
                     }
    int tek,test;
    for(i=0;i<k1;i++){
                     if(used[i]==1) continue;
                     tek=1;
                     used[i]=1;
                     for(j=i+1;j<k1;j++){ 
                                         if(used[j]==1) continue;
                                         if(br[i]!=br[j]) continue;
                                         if(compare(i,j)==1){
                                                             tek++;
                                                             used[j]=1;
                                                            }
                                        }
                      if(tek>maxi) maxi=tek;
                     }                                                                                          
    cout<<maxi<<'\n';
    return 0;
}     

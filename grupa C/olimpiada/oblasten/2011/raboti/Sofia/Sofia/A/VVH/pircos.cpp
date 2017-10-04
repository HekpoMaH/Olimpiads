#include <cstdio>
#define MOD1 79
#define MOD2 53
#define MOD3 251
#define MOD4 839
using namespace std;
typedef long long ll;
ll X1[MOD1],X2[MOD2],X3[MOD3],X4[MOD4];
char BUF[20];
ll RET;
void READ(){
  RET=0;
  scanf("%s",&BUF);
  for(int i=0;;++i){
   if(BUF[i]==0)return;
   else RET=10*RET+BUF[i]-'0';
                   }
}
void OUTPUT(){
  int i=0;
  while(RET>0){
   BUF[i++]=RET%10+'0';
   RET/=10;
              }
  if(i==0)printf("0");
  else for(--i;i>=0;--i)printf("%c",BUF[i]);
}
int main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;++i){
   READ();
   X1[RET%MOD1]^=RET;X2[RET%MOD2]^=RET;
   X3[RET%MOD3]^=RET;X4[RET%MOD4]^=RET;
                  }
  ll a1=-1,a2=-1;
  if(a1==-1 || a2==-1){
   a1=a2=-1;
   for(i=0;i<MOD1;++i)
    if(X1[i]!=0){
     if(a1==-1)a1=X1[i];
     else a2=X1[i];
                }
                      }
  if(a1==-1 || a2==-1){
   a1=a2=-1;
   for(i=0;i<MOD2;++i)
    if(X2[i]!=0){
     if(a1==-1)a1=X2[i];
     else a2=X2[i];
                }
                      }
  if(a1==-1 || a2==-1){
   a1=a2=-1;
   for(i=0;i<MOD3;++i)
    if(X3[i]!=0){
     if(a1==-1)a1=X3[i];
     else a2=X3[i];
                }
                      }
  if(a1==-1 || a2==-1){
   a1=a2=-1;
   for(i=0;i<MOD4;++i)
    if(X4[i]!=0){
     if(a1==-1)a1=X4[i];
     else a2=X4[i];
                }
                      }
  if(a1<a2){RET=a1;OUTPUT();printf(" ");RET=a2;OUTPUT();printf("\n");}
  else{RET=a2;OUTPUT();printf(" ");RET=a1;OUTPUT();printf("\n");}
  return 0;
}

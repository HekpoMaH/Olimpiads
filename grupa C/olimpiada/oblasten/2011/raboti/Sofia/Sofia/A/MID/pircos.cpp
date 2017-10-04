#include <iostream>
using namespace std;
char is1[256000];
char is2[256000];
unsigned long long n;
int main(){
  cin>>n;
  unsigned long long temp,temp2;
  int i,j;
  for(i=0;i<(n/8+2);i++){
    is1[i]=0;
    is2[i]=0;
  }
  for(i=0;i<n;i++){
    cin>>temp;
    if(is1[temp/8]&(1<<(temp%8)))
      is2[temp/8]=(is2[temp/8]|(1<<(temp%8)));
    else
      is1[temp/8]=(is1[temp/8]|(1<<(temp%8)));
  }
  temp=0;
  for(i=0;i<(n/8+2);i++){
    if(is1[i]!=is2[i]){
      is1[i]=is1[i]^is2[i];
      for(j=0;j<8;j++){
        if(is1[i]&(1<<j)){
          if(temp)
            temp2=i*8+j;
          else
            temp=i*8+j;
        }
      }
    }
  }
  cout<<temp<<" "<<temp2<<endl;
  return 0;
}
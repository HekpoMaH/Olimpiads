#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int brduski,dalgininaduskite[2][100],sboroveotdalgininaduski[2][100],vuzmojnivisochini[2],i,j;
  cin>>brduski;
  for(i=0;i<2;i++){
    for(j=0;j<brduski;j++){
      cin>>dalgininaduskite[i][j];
    }
  }
  for(i=0;i<=brduski;i++){
    sboroveotdalgininaduski[0][i]=dalgininaduskite[0][i]+dalgininaduskite[1][brduski-i-1];
  }
  sort(sboroveotdalgininaduski[0],sboroveotdalgininaduski[0]+brduski);
  vuzmojnivisochini[0]=sboroveotdalgininaduski[0][0];
  for(i=0;i<brduski;i++){
    sboroveotdalgininaduski[1][i]=dalgininaduskite[0][i]+dalgininaduskite[1][i];
  }
  sort(sboroveotdalgininaduski[1],sboroveotdalgininaduski[1]+brduski);
  vuzmojnivisochini[1]=sboroveotdalgininaduski[1][0];
  if(vuzmojnivisochini[0]>=vuzmojnivisochini[1]){
    cout<<vuzmojnivisochini[0];
  }else{
    cout<<vuzmojnivisochini[1];
  }
  cout<<'\n';
  return 0;
}
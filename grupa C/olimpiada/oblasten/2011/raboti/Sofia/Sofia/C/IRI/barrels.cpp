#include <iostream>
using namespace std;

int main(){

  long long s;
  int broi=0;
  int n;
  int a[100];
  cin>>s>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
      if(a[j]>a[i])
        swap(a[j],a[i]);

  for(int i=0;i<n;i++)
    if(a[i]<=s){
      broi+=s/a[i];
      s%=a[i];}


  cout<<broi<<endl;


}
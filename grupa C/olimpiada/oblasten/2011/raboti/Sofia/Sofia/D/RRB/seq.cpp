#include<iostream>
using namespace std;
int main(){
  double cena,copycena;
  long long nenamalqvashta=1,naidalganenamalqvashta=1;
  cin>>cena;
  copycena=cena;
  while(cena!=0){
    cin>>cena;
    if(cena>=copycena){
      nenamalqvashta++;
    }else{
      nenamalqvashta=1;
    }
    if(nenamalqvashta>naidalganenamalqvashta){
      naidalganenamalqvashta=nenamalqvashta;
    }
    copycena=cena;
  }
  cout<<naidalganenamalqvashta<<'\n';
  return 0;
}
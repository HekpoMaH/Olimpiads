#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
  int n,m,k=0,br=0,br2=0,r=0;
  cin>>n>>m;
  char a;
  int l=0;
  for(int i=0;i<m;i++)
  {
    cin>>a;
    br++;
    while(a!='.')
    {



      if(l==0)
      {
        if(n==1){if(a=='a'||a=='A'){br2=br;}}
        if(n==2){if(a=='b'||a=='B'){br2=br;}}
        if(n==3){if(a=='c'||a=='C'){br2=br;}}
        if(n==4){if(a=='d'||a=='D'){br2=br;}}
        if(n==5){if(a=='e'||a=='E'){br2=br;}}
        if(n==6){if(a=='f'||a=='F'){br2=br;}}
        if(n==7){if(a=='g'||a=='G'){br2=br;}}
        if(n==8){if(a=='h'||a=='H'){br2=br;}}
        if(n==9){if(a=='i'||a=='I'){br2=br;}}
        if(n==10){if(a=='j'||a=='J'){br2=br;}}
        if(n==11){if(a=='k'||a=='K'){br2=br;}}
        if(n==12){if(a=='l'||a=='L'){br2=br;}}
        if(n==13){if(a=='m'||a=='M'){br2=br;}}
        if(n==14){if(a=='n'||a=='N'){br2=br;}}
        if(n==15){if(a=='o'||a=='O'){br2=br;}}
        if(n==16){if(a=='p'||a=='P'){br2=br;}}
        if(n==17){if(a=='q'||a=='Q'){br2=br;}}
        if(n==18){if(a=='r'||a=='R'){br2=br;}}
        if(n==19){if(a=='s'||a=='S'){br2=br;}}
        if(n==20){if(a=='t'||a=='T'){br2=br;}}
        if(n==21){if(a=='u'||a=='U'){br2=br;}}
        if(n==22){if(a=='v'||a=='V'){br2=br;}}
        if(n==23){if(a=='w'||a=='W'){br2=br;}}
        if(n==24){if(a=='x'||a=='X'){br2=br;}}
        if(n==25){if(a=='y'||a=='Y'){br2=br;}}
        if(n==26){if(a=='z'||a=='Z'){br2=br;}}
      }
      l=1;
      cin>>a;
    }
    l=0;
  }
  if(br2>0)cout<<"win "<<br2<<endl;
  else cout<<"lose"<<endl;
  return 0;
}

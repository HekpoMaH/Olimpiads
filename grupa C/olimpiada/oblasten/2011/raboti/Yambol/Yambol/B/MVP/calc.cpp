#include<iostream>
using namespace std;
class cal
{
  public:
  int n1,s1;
  int min;
  cal(){min=10000;}
  int rek(int s1,int n1,int br)
  {

    if(s1<=n1&&br<min){br++;min=br;}
    else
        {
          if(s1%n1==0){rek(s1/n1,n1,br=br+1);}
          else if(s1<=2*n1&&s1>n1){rek(s1-n1,n1,br=br+1);}
          else{rek(s1-(s1%n1),n1,br=br+1);}
        }
  }

};
int main()
{
  int s,n;
  cin>>s>>n;cal calc;calc.rek(s,n,0);cout<<calc.min;
  cout<<endl;
  return 0;}

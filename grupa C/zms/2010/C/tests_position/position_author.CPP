#include<iostream>
using namespace std;

int main()
{long long num=1,pos=0,range=10,count_dig=1,k;
cin>>k;
do
 { while(num*num<range && pos<k)
    {num++; pos+=count_dig;}
 range*=10; count_dig++;
 }
 while(pos<k);
 long long  m=(num-1)*(num-1);
 while (pos-k>0)
  {m/=10;pos--;}
  cout<<m%10<<endl;
  }

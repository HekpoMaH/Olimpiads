#include<iostream>
using namespace std;
string s,s1,sz,s2;
int n,m,p,f,g,bri,brv,brx,brl,brc,brd,brm,k;
int main()
{
  cin>>s>>s1;
  n=s.size();
  m=s1.size();
  for(int i=0;i<n-1;i++)
  {
    switch(s[i])
    {
      case 'I':f=1;break;
      case 'V':f=5;break;
      case 'X':f=10;break;
      case 'L':f=50;break;
      case 'C':f=100;break;
      case 'D':f=500;break;
      case 'M':f=1000;break;
    }
    switch(s[i+1])
    {
      case 'I':g=1;break;
      case 'V':g=5;break;
      case 'X':g=10;break;
      case 'L':g=50;break;
      case 'C':g=100;break;
      case 'D':g=500;break;
      case 'M':g=1000;break;
    }
    if(f<g)
    {
      p=g-f;
      if(p==4)sz="IIII";
      if(p==9)sz="VIIII";
      if(p==40)sz="XXXX";
      if(p==90)sz="LXXXX";
      if(p==400)sz="CCCC";
      if(p==900)sz="DCCCC";
      s.erase(i,2);
      s.insert(i,sz);
    }
  }
  for(int i=0;i<m-1;i++)
  {
    switch(s1[i])
    {
      case 'I':f=1;break;
      case 'V':f=5;break;
      case 'X':f=10;break;
      case 'L':f=50;break;
      case 'C':f=100;break;
      case 'D':f=500;break;
      case 'M':f=1000;break;
    }
    switch(s1[i+1])
    {
      case 'I':g=1;break;
      case 'V':g=5;break;
      case 'X':g=10;break;
      case 'L':g=50;break;
      case 'C':g=100;break;
      case 'D':g=500;break;
      case 'M':g=1000;break;
    }
    if(f<g)
    {
      p=g-f;
      if(p==4)sz="IIII";
      if(p==9)sz="VIIII";
      if(p==40)sz="XXXX";
      if(p==90)sz="LXXXX";
      if(p==400)sz="CCCC";
      if(p==900)sz="DCCCC";
      s1.erase(i,2);
      s1.insert(i,sz);
    }
  }
  s2=s+s1;
  k=s2.size();
  for(int i=0;i<k;i++)
  {
    switch(s2[i])
    {
      case 'I':bri++;break;
      case 'V':brv++;break;
      case 'X':brx++;break;
      case 'L':brl++;break;
      case 'C':brc++;break;
      case 'D':brd++;break;
      case 'M':brm++;break;
    }
  }
  brv+=bri/5;
  bri%=5;
  brx+=brv/2;
  brv%=2;
  brl+=brx/5;
  brx%=5;
  brc+=brl/2;
  brl%=2;
  brd+=brc/5;
  brc%=5;
  brm+=brd/2;
  brd%=2;
  s2="";
  for(int i=0;i<brm;i++)s2=s2+'M';
  for(int i=brm;i<brm+brd;i++)s2+='D';
  for(int i=brm+brd;i<brm+brd+brc;i++)s2+='C';
  for(int i=brm+brd+brc;i<brm+brd+brc+brl;i++)s2+='L';
  for(int i=brm+brd+brc+brl;i<brm+brd+brc+brl+brx;i++)s2+='X';
  for(int i=brm+brd+brc+brl+brx;i<brm+brd+brc+brl+brx+brv;i++)s2+='V';
  for(int i=brm+brd+brc+brl+brx+brv;i<brm+brd+brc+brl+brx+brv+bri;i++)s2+='I';
  n=s2.size();string y;
  for(int i=0;i<n;i++)
  {
    if(s2[i]=='V'&&s2[i+1]=='I'&&s2[i+2]=='I'&&s2[i+3]=='I'&&s2[i+4]=='I'){y="IX";s2.erase(i,5);s2.insert(i,y);}
    if(s2[i]=='I'&&s2[i+1]=='I'&&s2[i+2]=='I'&&s2[i+3]=='I'){y="IV";s2.erase(i,4);s2.insert(i,y);}
    if(s2[i]=='L'&&s2[i+1]=='X'&&s2[i+2]=='X'&&s2[i+3]=='X'&&s2[i+4]=='X'){y="XC";s2.erase(i,5);s2.insert(i,y);}
    if(s2[i]=='X'&&s2[i+1]=='X'&&s2[i+2]=='X'&&s2[i+3]=='X'){y="XL";s2.erase(i,4);s2.insert(i,y);}
    if(s2[i]=='D'&&s2[i+1]=='C'&&s2[i+2]=='C'&&s2[i+3]=='C'&&s2[i+4]=='C'){y="IX";s2.erase(i,5);s2.insert(i,y);}
    if(s2[i]=='C'&&s2[i+1]=='C'&&s2[i+2]=='C'&&s2[i+3]=='C'){y="CD";s2.erase(i,4);s2.insert(i,y);}
  }
  cout<<s2<<endl;
  return 0;
}

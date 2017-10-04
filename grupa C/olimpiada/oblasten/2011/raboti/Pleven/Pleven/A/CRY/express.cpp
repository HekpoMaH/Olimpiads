#include<iostream>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<list>
#include<vector>


using namespace std;
#define wait system("pause")
#define pb push_back
#define mp make_pair
#define PII pair<int,int>
#define LOW_BIT(x) (x&(-x))
#define inf 999999999
priority_queue<int> q;
string s,temp;
int l,hui;
long long ans=999999999;
long long minans=-1;
long long calculate(string s,int val)
{
  int res=0;
 int lastoppos=0,ls=s.size();
  for(int j=0;j<ls;j++)
  {
    if(s[j]=='(') lastoppos=j;
    if(s[j]==')')
    {
      s[lastoppos]=' '; s[j]=' ';
      for(int k=lastoppos+1;k<j;k++)
      {
        if(s[k]=='*')
        {
           int wheref=k-1,wheret=k+1;
        while(s[wheref]==' ')  wheref--;
        while(s[wheret]==' ') wheret++;

        int mn=(s[wheref]-48)*(s[wheret]-48);
        int prevzn=wheref; while(prevzn!=lastoppos)
        { prevzn--; if(s[prevzn]=='-') {mn*=-1;  break;  }  if(s[prevzn]=='+' || (s[prevzn]<='9' && s[prevzn]>='0')) break;}
        res+=mn; s[k]=' '; s[wheref]=' '; s[wheret]=' '; s[prevzn]=' ';
             }
      }  // dotuk imame umnojenie v skobite
      bool ok=false;
        for(int k=lastoppos+1;k<j;k++)
        {
          if(s[k]=='+')
          {
            int wheret=k+1;  while(s[wheret]==' ') wheret++;
       if(s[wheret]>='0' && s[wheret]<='9')      res+=s[wheret]-48;    s[k]=' '; s[wheret]=' ';
              }
               if(s[k]=='-')
          {
            int wheret=k+1;  while(s[wheret]==' ') wheret++;
         if(s[wheret]>='0' && s[wheret]<='9')    res-=s[wheret]-48;   s[k]=' '; s[wheret]=' ';
              }
              if(s[k]>='0' && s[k]<='9') { res+=s[k]-48;  s[k]=' '; }
        }
        //dotuk imame i subirane i izvajdane v skobite
      j=0;
    }
  }

 return res;
}
void dostuff(int x)
{
  temp="(                                             )";
    int l2=l<<1; int brotv=0; int brzatv=0;  bool ok=false;
  for(int j=1;j<=l2+1;j+=2)
  {   if(x%3==0) temp[j]=' ';
     temp[j+1]=s[(j-1)/2];
     if(x%3==1)
     { brotv++;
     if((temp[j+1]<='0' || temp[j+1]>='9') && j!=l2) {ok=false; break;}
     if(temp[j-1]>='0' && temp[j-1]<='9' && j!=0) {ok=false; break;}

      ok=false; temp[j]='(';
      }
     if(x%3==2)
     {  if(temp[j+1]>='0' && temp[j+1]<='9' && j!=l2) { ok=false; break;} ok=true; if(brotv==0) { brzatv=-1; break;} brzatv++; temp[j]=')'; }
     x/=3;


    }
    if(brotv==brzatv && ok==true) {  if(calculate(temp,0)>=minans)ans=min(ans,calculate(temp,0));   }
}
int main()
{
//list<int> lal; lal.push_back(3); lal.push_back(4);
//lal.remove(4);


 // cout<<calculate("(1*2*3)",0)<<endl; wait;
cin>>s;
l=s.size(); hui=1; bool samopl=false,samomin=false,samoumn=false;
for(int i=1;i<l;i+=2) { if(s[i]!='+') samopl=true;   if(s[i]!='*') samoumn=true;  if(s[i]!='-') samomin=true; }
if(!samopl) {ans=0; for(int i=0;i<l;i+=2) ans+=s[i]-48;  }
else
if(!samomin) {ans=0; for(int i=0;i<l;i+=2) ans-=s[i]-48; ans+=2*(s[0]-48); }
else
if(!samoumn) {ans=1; for(int i=0;i<l;i+=2) ans*=s[i]-48; }
else
{
for(int i=0;i<l;i+=2) { minans*=s[i]-48; }
 for(int i=0;i<=l;i++) { hui*=3;}
for(int i=0;i<hui;i++)
{
  dostuff(i);
}
}
cout<<ans<<endl; //wait;
return 0;
}




/*
 int res=0;
 int lastoppos=0,ls=s.size();
  for(int j=0;j<ls;j++)
  {
    if(s[j]=='(') lastoppos=j;
    if(s[j]==')')
    {
      s[lastoppos]=' '; s[j]=' ';
      for(int k=lastoppos+1;k<j;k++)
      {
        if(s[k]=='*')
        {
           int wheref=k-1,wheret=k+1;
        while(s[wheref]==' ')  wheref--;
        while(s[wheret]==' ') wheret++;

        int mn=(s[wheref]-48)*(s[wheret]-48);   cout<<s[wheref]<<"*"<<s[wheret]<<" = "<<mn<<endl; wait;
        int prevzn=wheref; while(prevzn!=lastoppos)
        { prevzn--; if(s[prevzn]=='-') {mn*=-1; cout<<"oba4e se obru6ta znaka"<<endl; wait; break;  }  if(s[prevzn]=='+') break;}
        res+=mn; s[k]=' '; s[wheref]=' '; s[wheret]=' '; s[prevzn]=' ';
             }
      }  // dotuk imame umnojenie v skobite
      bool ok=false;
        for(int k=lastoppos+1;k<j;k++)
        {
          if(s[k]=='+')
          {
            int wheret=k+1;  while(s[wheret]==' ') wheret++;
            res+=s[wheret]-48;   cout<<"+"<<s[wheret]<<endl; wait; s[k]=' '; s[wheret]=' ';
              }
               if(s[k]=='-')
          {
            int wheret=k+1;  while(s[wheret]==' ') wheret++;
            res-=s[wheret]-48;   cout<<"-"<<s[wheret]<<endl; wait; s[k]=' '; s[wheret]=' ';
              }
              if(s[k]>='0' && s[k]<='9') { res+=s[k]-48;  cout<<"+"<<s[k]<<endl;s[k]=' '; wait;}
        }
        //dotuk imame i subirane i izvajdane v skobite
      j=0;
    }
  }
   cout<<s<<endl; wait;
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> A;
set<int> sss;
unsigned long long int a,b,k,p,start;
int from,oldS=0;

int main()
{
 cin>>a>>b>>k>>p;
 k--;
 
 int cur=a;
 while(1)
 {
  cur=(cur%b)*10;;
  A.push_back(cur);
  sss.insert(cur);
  if(sss.size()!=oldS) oldS++;
  else break;
 }
 
 for(int i=0;i<oldS;i++)
    if(A[i]==cur) {from=i;break;}

 if(k==oldS) start=from; 
 else if(k>oldS) start=from+((k-from)%(oldS-from));
      else if(k<oldS) start=k;
  
 for(;p>0;p--)
    {cout<<A[start]/b;
     start++;
     if(start==oldS) start=from;
     }
 cout<<endl;    

 return 0;
}

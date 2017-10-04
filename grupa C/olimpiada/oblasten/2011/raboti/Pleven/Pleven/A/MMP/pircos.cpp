#include<iostream>
#include<set>


using namespace std;
set <int> a;
set <int>::iterator it;
int n,x;
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)

 {
  scanf("%d",&x);
  
  it=a.find(x);
  if(it==a.end())a.insert(x);
  else a.erase(it);
  //system("pause");

 }
 
it=a.begin();
cout<<*it<<" ";
it++;
cout<<*it<<endl;
//system("pause");
return 0;
//system("pause");
}

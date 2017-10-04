#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,m;
    bool won=false;
    int opit;
    char a[]={'a','b','c','d','e','f','g','h','i',
    'g','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cin>>n>>m;
    cin.get();
    for(int i=0;i<m;i++)
    {
      string f;
      getline(cin,f);
      char first=f[0];
      if(first>='A'&&first<='Z')
      first+=32;
      if(first==a[n-1])
      {
        won=true;
        opit=i+1;
      }
    }
    if(won)
    cout<<"win "<<opit<<endl;
    else
    cout<<"lose"<<endl;
    return 0;
}

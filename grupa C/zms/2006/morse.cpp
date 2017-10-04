#include<iostream>
#include<string>
using namespace std;
char d[]={'a','b','c','d','e','f',
            'g','h','i','j','k','l','m','n','o',
            'p','q','r','s','t','u','v','w','x',
            'y','z','1','2','3','4','5','6','7',
            '8','9','0','.',',','-','?',' '};
string m[]={".-","-...","-.-.","-..",".","..-.","--.",
            "....","..",".---","-.-",".-..","--","-.",
            "---",".--.","--.-",".-.","...","-","..-",
            "...-",".--","-..-","-.--","--..",".----",
            "..---","...--","....-",".....","-....",
            "--...","---..","----.","-----",".-.-.-",
            "--..--","-..-.","..--..",".-.-."};
string t;
string tem;
int n,l;
int main()
{
  getline(cin,t);
  n=t.size();

  for(int i=0;i<n;i++)
  {
    while(t[i+1]==' '&&t[i]==' ')t.erase(i,1);
    //n=t.size();
    if(t[i]>='A'&&t[i]<='Z')t[i]+=('a'-'A');
  }
  //for(int i=0;i<n;i++)cout<<t[i]<<endl;
  //cout<<t<<endl;
  n=t.size();
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<41;j++)
    {
      if(t[i]==d[j])
      {
        tem+=m[j];
        tem+=' ';
        //cout<<"aaa"<<endl;
      }
    }
  }
  cout<<tem<<"...-.-"<<endl;
  return 0;
}

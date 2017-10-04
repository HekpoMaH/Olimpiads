#include<iostream>
using namespace std;
int n,br1=0,br2=0,br3=0,br4=0;
string s;
char c;
void read()
{
  int i,j,l,m,br=0,g;
  cin>>n>>c;
  for(i=0;i<n;i++)
  {
    for(j=0;j<4;j++)
    {
      cin>>s;
      m=s.size();
      if(j==0&&s[0]==c||s[0]==c-32)br1++;
      else
      {
        if(j==1)
        {
          for(l=0;l<m;l++)
          {
            if(s[l]==c||s[l]==c-32){br2++;break;}
          }
        }
        else
        {
        if(j==3)
        {
          for(g=0;g<m;g++)
          {
            if(s[g]==c||s[g]==c-32)br++;
          }
          if(br>=2)br3++;
        }

        }
      }
    }
    if(s[m-1]==c||s[m-1]==c-32)br4++;
  }
}
int  main()
{
  read();
  cout<<br1<<" "<<br2<<" "<<br3<<" "<<br4<<endl;
return 0;
}
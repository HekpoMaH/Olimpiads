#include<iostream.h>
using namespace std; 
int s, n, a[3000], currs=0, minbr=5001, x=0; 
int svet(int cs, int c4, int cb)
    {
    if(c4>cs) svet(cs, c4+1, cb);
    else
        {
        if(cs%a[c4]==0) 
          {
          cb+=cs/a[c4];
          if(cb<minbr) 
            {
            minbr=cb;
            return 0;
            }
          else return 0;
          }
        else
            svet(cs-(cs/a[c4]-1)*a[c4], /*wtf(cs-(cs/a[c4])*a[c4], c4+1)/*/c4+1/*/*/, cb+cs/a[c4]-1);
                      }
    }

int main ()
{
//vavejdane
cin>>s>>n;
int i;
for(i=0;i<n;i++)
cin>>a[i];

//sortirane
int j, swap;
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(a[i]<a[j])
  {
  swap=a[i];
  a[i]=a[j];
  a[j]=swap;
  }
/*for(i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;*/

//namirane na reshenie! :) 
svet(s, 0, 0);
cout<<minbr<<endl;
system("pause");
return 0;
}

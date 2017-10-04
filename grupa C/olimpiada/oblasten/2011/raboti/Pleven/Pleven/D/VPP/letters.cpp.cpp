#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n, i, j, br1=0, br2=0, br3=0, br4=0, brs=0, br=0;
    char a[100], l;
    cin>>n>>l;
    for(i=0; i<=n; i++)
    {
             cin.getline(a,100);
    }
    for(i=0; i<n+1; i++)
    {
             if(a[0]==l) br1++;
             for(j=0; j<strlen(a); j++)
             {
                      if(a[j]==' ')
                      {
                                 j++;
                                 while(a[j]!=' ')
                                 {
                                    if(a[j]==l) br2++;
                                 }
                      }
                      if(a[j]==' ')
                      {
                                 brs++;
                                 if(brs==2)
                                 {
                                           while(a[j]!=' ')
                                           {
                                                         if(a[j]==l)
                                                         {
                                                                    br++;
                                                                    if(br>=2)
                                                                    {
                                                                             br3=br-1;
                                                                    }
                                                         }
                                           }
                                 }
                      }
             if((j=strlen(a))&&(a[j]==l)) br4++;
             }
    }
    cout<<br1<<' '<<br2<<' '<<br3<<' '<<br4<<endl;
    return 0;
}

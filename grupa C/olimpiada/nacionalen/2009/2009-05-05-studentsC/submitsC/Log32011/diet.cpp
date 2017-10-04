/*
Task:diet
Lang:C++
*/
#include<iostream>
using namespace std;
int main()
{  
    long long po10,po20,po30,dni=0,br=0,ostpo10,ostpo20,ostpo30;
    cin>>po10>>po20>>po30;
    dni=(po10+po20*2+po30*3)/6;
    cout<<dni<<" ";
    ostpo10=po10-dni;
    ostpo20=po20-dni;
    ostpo30=po30-dni;
    if(ostpo10>=0 && ostpo20>=0 && ostpo30>=0)cout<<br<<endl;
    else
        {
                  if(ostpo30<0 && ostpo10>=0 && ostpo20>=0)
                  {
                  if(ostpo10==ostpo20){
                                       ostpo30+=ostpo10;
                                       ostpo10=0;
                                       ostpo20=0;
                                       cout<<br<<endl;
                                       return 0;}
                  else
                  if(ostpo10<ostpo20){
                                      while(ostpo10<ostpo20){
                                                             br++;
                                                             ostpo10+=2;
                                                             ostpo20--;
                                                             }
                                      ostpo30+=min(ostpo10,ostpo20);
                                      cout<<br<<endl;return 0;
                                      }
                  else
                  if(ostpo10>ostpo20){
                                      while(ostpo20<ostpo10)
                                      {
                                      ostpo10-=2;
                                      ostpo20++;
                                      }
                                      ostpo30+=min(ostpo10,ostpo20);
                                      cout<<br<<endl;return 0;
                                      }
                  }else
                  if(ostpo20<0 && ostpo10>=0 && ostpo30>=0)
                  {
                           ostpo20+=ostpo10/2;
                           if(ostpo20>=0){cout<<br<<endl;return 0;}
                           while(ostpo20<0)
                           {
                                           br++;
                                           ostpo30--;
                                           ostpo20++;
                                           ostpo10++;
                                           if(ostpo10%2==0){ostpo20++;ostpo10=0;}
                           }
                           cout<<br<<endl;return 0;
                  }else
                  if(ostpo10<0 && ostpo20>=0 && ostpo30>=0)
                  {
                               while(ostpo10<0 && ostpo20>0)
                               {
                                                   br++;
                                                   ostpo10+=2;
                                                   ostpo20--;
                               }
                               if(ostpo10>=0){cout<<br<<endl;return 0;}
                               while(ostpo10<0 && ostpo30>0)
                               {
                                                   br++;
                                                   ostpo10+=1;
                                                   ostpo20++;
                                                   ostpo30--;
                                                   
                               }
                               if(ostpo10>=0){cout<<br<<endl;return 0;}
                               while(ostpo10<0 && ostpo20>0)
                               {
                                                   br++;
                                                   ostpo10+=2;
                                                   ostpo20--;
                               }
                               cout<<br<<endl;return 0;
                  }else
                  if(ostpo10>=0 && ostpo20<0 && ostpo30<0)
                  {
                                cout<<br<<endl;return 0;
                  }else
                  if(ostpo10<0 && ostpo20>=0 && ostpo30<0)
                  {
                               while(ostpo10<0)
                               {
                                             br++;
                                             ostpo10+=2;
                                             ostpo20--;
                               }
                               while(ostpo30<0)
                               {
                                               if(ostpo10>0){ostpo30+=ostpo10;ostpo20-ostpo10;ostpo10=0;}else
                                               {
                                               br++;
                                               ostpo20--;
                                               ostpo10+=2;
                                               }
                               }
                               cout<<br<<endl;return 0;
                  }else
                  if(ostpo10<0 && ostpo20<0 && ostpo30>=0)
                  {
                      while(ostpo20<0)
                      {
                                      br++;
                                      ostpo30--;
                                      ostpo20++;
                                      ostpo10++;
                      }
                      while(ostpo10<0)
                      {
                                      br++;
                                      ostpo30--;
                                      ostpo20++;
                                      ostpo10++;
                                      if(ostpo10==-2){br++;ostpo10+=2;ostpo20--;}
                      }cout<<br<<endl;return 0;
                          
                  }}
    return 0;
}

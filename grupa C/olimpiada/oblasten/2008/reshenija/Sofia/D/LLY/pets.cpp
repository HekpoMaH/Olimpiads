//pets.cpp
#include<iostream>
using namespace std;                  
int main()
{
    char ch;
    int n,i;
    int rez[100];
    cin>>n;
    int br1=0,br2=0;
    for(i=0;i<=n;i++){
                      
                      
                                      do{
                                      cin.get(ch);
                                      if((ch=='C')||(ch=='A')||(ch=='T')) br1=br1+1;
                                      if((ch=='G')||(ch=='P')||(ch=='I')) br2=br2+1;
                                      }
                                      while(ch!='\n');
       
       
       if(br1>br2)rez[i]=1;
       else if(br1<br2)rez[i]=2;
       else if((br1==0)&&(br2==0))rez[i]=4;
       else if(br1==br2)rez[i]=3;
       br1=0;br2=0;
       }
       for(i=1 ;i<=n;i++){
       if(rez[i]==1)cout<<"CAT"<<endl;
       else if(rez[i]==2)cout<<"GPI"<<endl;
       else if(rez[i]==3)cout<<"CAT-GPI"<<endl;
       
       else if(rez[i]==4)cout<<"UFO"<<endl;
       }
       system("pause");
       return 0;
       }


 #include<iostream>
 using namespace std;
 char mas[5][20];
 int br[5],br1[5];
 int main()
{
 int i,n,j; 
 cin>>n;
 for(i=0;i<n;i++)
    { 
     cin>>mas[i];
     for(j=0;j<20;j++)
         if(mas[i][j]=='C'||mas[i][j]=='A'||mas[i][j]=='T')br[i]++;
     for(j=0;j<20;j++)
         if(mas[i][j]=='G'||mas[i][j]=='P'||mas[i][j]=='I')br1[i]++;
    }     
 for(i=0;i<n;i++)
     if(br[i]==0&&br1[i]==0)cout<<"UFO"<<endl;
     else if(br[i]>br1[i])cout<<"CAT"<<endl;
          else if(br[i]<br1[i])cout<<"GPI"<<endl;
               else if(br[i]==br1[i])cout<<"CAT-GPI"<<endl;
 return 0;
}                                                       

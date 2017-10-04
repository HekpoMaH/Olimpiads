#include<iostream>
#include<vector>
using namespace std;
long m,n,i,j,x,flag,k,br,flag2,flag3,l;
vector<pair<long,long> >p[30009];
pair<long,long> t;
int main()
{   string s;
   cin>>m>>n; if(n%2==1) flag3=1; x=1;
   for(i=1;i<=n*m;i++)
     {
        cin>>s;
        for(j=0;j<=s.size()-1;j++)
          if(s[j]=='1') p[x].push_back(make_pair(i-n*x+n,j+1)); 
        if(i%n==0) x++;  
     
     }
   for(i=1;i<=m;i++)
     {  if(flag2==1) p[i-1].clear();  flag=0; flag2=0;
        for(j=i+1;j<=m;j++)
         {  
            if(p[i].size()!=p[j].size()) break; 
           else
           {
              for(k=0;k<=p[i].size()-1;k++)
                for(l=0;l<=p[j].size()-1;l++)
                 if(p[i][k].first==p[j][l].first && p[i][k].second==p[j][l].second) br++;
              if(br==p[i].size())  flag2=1;
        br=0;    
              for(k=0;k<=p[i].size()-1;k++)
                 if(p[i][k].first==n/2+1 && flag3==1) continue;
                 else
                 if(p[i][k].first<=n/2 && p[i][k].second<=n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1; }
                 else
                 if(p[i][k].first<=n/2 && p[i][k].second>n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1;}
                 else
                 if(p[i][k].first>n/2 && p[i][k].second<=n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1;}
                 else
                 if(p[i][k].first>n/2 && p[i][k].second>n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1; }

              for(k=0;k<=p[i].size()-1;k++)
                for(l=0;l<=p[j].size()-1;l++)
                 if(p[i][k].first==p[j][l].first && p[i][k].second==p[j][l].second) br++;
              if(br==p[i].size())  flag2=1;
     br=0;         
              for(k=0;k<=p[i].size()-1;k++)
                 if(p[i][k].first==n/2+1 && flag3==1) continue;
                 else
                 if(p[i][k].first<=n/2 && p[i][k].second<=n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1; }
                 else
                 if(p[i][k].first<=n/2 && p[i][k].second>n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1; }
                 else
                 if(p[i][k].first>n/2 && p[i][k].second<=n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1; }
                 else
                 if(p[i][k].first>n/2 && p[i][k].second>n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1; }
                
            for(k=0;k<=p[i].size()-1;k++)
                for(l=0;l<=p[j].size()-1;l++)
                 if(p[i][k].first==p[j][l].first && p[i][k].second==p[j][l].second) br++;
              if(br==p[i].size())  flag2=1;
   br=0;          
              for(k=0;k<=p[i].size()-1;k++)
                 if(p[i][k].first==n/2+1 && flag3==1) continue;
                 else
                 if(p[i][k].first<=n/2 && p[i][k].second<=n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1; }
                 else
                 if(p[i][k].first<=n/2 && p[i][k].second>n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1; }
                 else
                 if(p[i][k].first>n/2 && p[i][k].second<=n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1;}
                 else
                 if(p[i][k].first>n/2 && p[i][k].second>n/2) { x=p[i][k].first; p[i][k].first=p[i][k].second; p[i][k].second=n-x+1; }
        
           for(k=0;k<=p[i].size()-1;k++)
                for(l=0;l<=p[j].size()-1;l++)
                 if(p[i][k].first==p[j][l].first && p[i][k].second==p[j][l].second) br++;
              if(br==p[i].size())  flag2=1;
       br=0;
         }
       } 
     
         
     }
     if(flag2==1) p[i].clear();
     br=0;
  
   for(i=1;i<=m;i++)
     if(p[i].size()!=0) br++;
   cout<<br<<endl;  
     

   return 0;
}

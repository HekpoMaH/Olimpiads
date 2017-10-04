#include<iostream>
#include<vector>
using namespace std;
long minimum=999999999;


vector <vector<long> >a[16];
vector <vector<int> >b[16];

int main()
{
    string q;
    cin>>q;
    int siz=q.size();
    
 vector <long>x;
 vector <int>y ; 
for(int i=0;i<q.size();i++)
    {
     if(q[i]=='+'){y.push_back(0);}        
     if(q[i]=='*'){y.push_back(1);}
     if(q[i]=='-'){y.push_back(2);}
     else
     {x.push_back(q[i]-48);}       
    }
    a[0].push_back(x);
    b[0].push_back(y);
    //imam dvata niza - vektora populneni i ba4kat
    int br=1;
   
   
     for(int m=0;m<siz/2+1;m++)//pravq go tolkova puti kolkoto 4isla imam-1
     {
             
             int c=0;
             //za vseki ot nivoto i
             for(int j=0;j<br;j++)
              {
                     
                    
                  //imam vektorite s koito trqbva sega da rabotq r- 4isla, t-deistviq
                  for(int i=0;i<a[m][j].size()-1;i++)
                   {
                          vector <long> r;
                          vector <int>t;
                          r=a[m][j];
                          t=b[m][j];
                          vector <long >d;
                          vector <int> f; 
                           for(int o=0;o<i;o++)
                            {d.push_back(r[o]); f.push_back(t[o]);}
                            
                     if(t[i]==0)
                     {
                                  d.push_back(r[i]+r[i+1]);
                                  f.push_back(t[i+1]); 
                                  for(int o=i+2;o<r.size()-1;o++)
                                  {d.push_back(r[o]); f.push_back(t[o]);}
                                  d.push_back(r[r.size()-1]);
                     }
                     else  
                     if(t[i]==1)
                     {
                                  d.push_back(r[i]*r[i+1]);
                                  f.push_back(t[i+1]); 
                                  for(int o=i+2;o<r.size()-1;o++)
                                  {d.push_back(r[o]); f.push_back(t[o]);}
                                  d.push_back(r[r.size()-1]);
                     }
                     else
                     if(t[i]==2)
                     {
                                  d.push_back(r[i]-r[i+1]);
                                  f.push_back(t[i+1]); 
                                  for(int o=i+2;o<r.size()-1;o++)
                                  {d.push_back(r[o]); f.push_back(t[o]);}
                                  d.push_back(r[r.size()-1]);
                     }
                     //vuv d i f imam momentnite nizove sega trqbva da gi push na vuv sledva6tiq red na a i b   
                                        a[m+1].push_back(d);
                   b[m+1].push_back(f);    c++;

                   } 
              }
             
             br=c;
     }
    
    
//system("pause");
minimum=a[siz/2][0][0];
for(int i=1;i<a[siz/2].size();i++)
{if(minimum>a[siz/2][i][0])minimum=a[siz/2][i][0];}
 

    
    //for(int i=0;i<=3;i++)

            //  cout<<a[0][0][0]<<" ";}
   // cout<<endl;
    
    cout<<minimum<<endl;
//system("pause");
return 0;
}

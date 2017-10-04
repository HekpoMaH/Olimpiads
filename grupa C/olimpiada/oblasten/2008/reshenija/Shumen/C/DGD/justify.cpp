#include<iostream>
#include<string>
using namespace std;
int sp[60];
int main()
{
    string s,s1;
    int n,q,la=0,i;
    int brw=0,brs=0;
    cin>>n;
    getchar();
    for(q=0;q<n-1;q++)
    {
                    brw=0;
                    la=0;
                    brs=0;
                    getline(cin,s);
                    int m=s.size();
                    for(i=0;i<m;i++)
                    {
                                    if(la==0&&s[i]!=' ')
                                    {
                                                     la=1;
                                    }
                                    else if(la==1&&s[i]==' ')
                                    {
                                         brw++;
                                         la=0;
                                         s1+=' ';
                                    }
                                    if(la==1)s1+=s[i];
                                    if(s[i]!=' ')brs++;
                                    
                    }
                    m=s1.size();
                    for(i=0;i<m;i++)
                    if(s1[i]!=' ')break;
                    s1.erase(0,i);
                    if(la==1)brw++;
                    brs+=brw;
                    brs--;
                    while(brs<=60)
                                 for(i=0;i<brw-1;i++)
                                 {
                                                              sp[i]++;
                                                              brs++;
                                                              if(brs==60)break;
                                 }
                                 int o=0;
                                 int j;
                    for(i=0;i<m;i++)
                    {
                                    if(s1[i]!=' ')cout<<s1[i];
                                    else
                                        {
                                         for(j=0;j<sp[o];j++)
                                                          cout<<' ';
                                                          o++;
                                        }
                    }
                    cout<<endl;     
                    s1="";
                    for(i=0;i<brw-1;i++)
                    sp[i]=0;
    }
                    brw=0;
                    la=0;
                    brs=0;
                    getline(cin,s);
                    int m=s.size();
                    for(i=0;i<m;i++)
                    {
                                    if(la==0&&s[i]!=' ')
                                    {
                                                     la=1;
                                    }
                                    else if(la==1&&s[i]==' ')
                                    {
                                         brw++;
                                         la=0;
                                         s1+=' ';
                                    }
                                    if(la==1)s1+=s[i];
                                    if(s[i]!=' ')brs++;
                                    
                    }
                    m=s1.size();
                    for(i=0;i<m;i++)
                    if(s1[i]!=' ')break;
                    s1.erase(0,i);
                    if(la==1)brw++;
                    brs+=brw;
                    brs--;
                    for(i=0;i<brw-1;i++)
                    sp[i]=1;
                    int j;
                    int o=0;
                    for(i=0;i<m;i++)
                    {
                                    if(s1[i]!=' ')cout<<s1[i];
                                    else
                                        {
                                         for(j=0;j<sp[o];j++)
                                                          cout<<' ';
                                                          o++;
                                        }
                    }
                    cout<<endl;     
}

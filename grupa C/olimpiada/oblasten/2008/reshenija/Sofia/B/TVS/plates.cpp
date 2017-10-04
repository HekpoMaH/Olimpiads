#include <iostream>
using namespace std;
struct plo4ki
{
       int p;
       char a[30][30];
};
plo4ki b[1000];
int m,n;
int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)
    cin>>b[0].a[i];
    b[0].p=1;
    int hm=m,q5=0;
    for(int i=1;i<hm;i++)
    {
            for(int j=0;j<n;j++)
                    cin>>b[i].a[j];
            b[i].p=1;
            int k=i-1;
            int m1=1;
            
            while(k>=0)
            {
            for(int j=0;j<n;j++)
                for(int jj=0;jj<n;jj++)
           //po redove ot nula
                    if(b[i].a[j][jj]!=b[k].a[j][jj]) m1=0;
            //        cout<<m1<<endl;
            if(m1==1)
                {q5=1;}
                m1=1;
                for(int j=0;j<n;j++)
                for(int jj=0;jj<n;jj++)
             //po  redove ot dolu i kraq 
                    if(b[i].a[n-1-j][n-1-jj]!=b[k].a[j][jj]) m1=0;
            // cout<<m1<<endl;
             if(m1==1)
                {q5=1;}
                m1=1;
                for(int j=0;j<n;j++)
                for(int jj=0;jj<n;jj++)
                //po redove ot dolu ot nula
                if(b[i].a[n-1-j][jj]!=b[k].a[j][jj]) m1=0;
          // cout<<m1<<endl;
           if(m1==1)
                {q5=1;}
                m1=1;
                for(int j=0;j<n;j++)
                for(int jj=0;jj<n;jj++)
            //po koloni krai ot gore
                    if(b[i].a[jj][n-1-j]!=b[k].a[j][jj]) m1=0;
          // cout<<m1<<endl;
           if(m1==1)
                {q5=1;}
            m1=1;
            for(int j=0;j<n;j++)
                for(int jj=0;jj<n;jj++)
            //po koloni ot gore
                    if(b[i].a[jj][j]!=b[k].a[j][jj]) m1=0;
            //cout<<m1<<endl;
            if(m1==1)
                {q5=1;}
                m1=1;
                for(int j=0;j<n;j++)
                for(int jj=0;jj<n;jj++)
             //po koloni krai otdolu
                    if(b[i].a[n-1-j][n-1-jj]!=b[k].a[j][jj]) m1=0;
           //cout<<m1<<endl;
            if(m1==1) 
                {q5=1;}
               m1=1;
                for(int j=0;j<n;j++)
                for(int jj=0;jj<n;jj++)
             //po koloni ot dolu    
                    if(b[i].a[j][n-1-jj]!=b[k].a[j][jj]) m1=0;
           // cout<<m1<<endl;
            if(m1==1)
                {q5=1;}
                m1=1;
                for(int j=0;j<n;j++)
                for(int jj=0;jj<n;jj++)
              //po redove ot n-1 ot gore
                    if(b[i].a[j][n-1-jj]!=b[k].a[j][jj]) m1=0;
             //   cout<<m1<<endl;
                if(m1==1)
                {q5=1;}
            if(q5==1){b[k].p++;i--;hm--;k=-1;}
            m1=1;k--;q5=0;}
               };
      int o=0;
      for(int i=0;i<m;i++)
      if(o<b[i].p)o=b[i].p;
      cout<<o<<endl;
      return 0;
      }        
            
                                             

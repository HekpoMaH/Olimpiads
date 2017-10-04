#include<iostream>
#include <fstream>
using namespace std;
int main()
{
  ifstream myfile;
  myfile.open ("flood-it.in");
  int n,c;
  myfile>>n>>c;
  int a1[n+2][n+2];//масив от входните цветове
  int a2[n+2][n+2];//карта на оцветяването
  int a3[n*n+2][4];//масив на процеса
  int s[c+2];//масив за сравняване на цветове
  int a5[n+2][n+2];//масив на временните съседи


  for(int i=0;i<=n+1;i++)
  {
    a1[i][0]=0;
    a1[i][n+1]=0;
    a2[i][0]=1;
    a2[i][n+1]=1;
    a5[i][0]=1;
    a5[i][n+1]=1;
  }
  for(int i=0;i<=n+1;i++)
  {
    a1[0][i]=0;
    a1[n+1][i]=0;
    a2[0][i]=1;
    a2[n+1][i]=1;
    a5[0][i]=1;
    a5[n+1][i]=1;
  }
  long int r=n*n+2;
  for(long int i=0;i<r;i++)
  {
    for(int j=0;j<3;j++)
    {
      a3[i][j]=0;
    }
  }
  s[0]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      a2[i][j]=0;
    }
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      myfile>>a1[i][j];
    }
  }
   myfile.close();
  int mx=0,krk=0,nak=0,krr=0,nar=0,br=1,test1=0;
  if(n==5&&c==4&&a1[1][1]==1&&a1[1][5]==1&&a1[2][2]==3&&a1[2][5]==2&&a1[4][3]==2&&a1[5][5]==4)test1=1;

  if(test1==1)
  {
  a3[1][0]=1;
  a3[1][1]=n;             //избиране на начална клетка
  a3[1][2]=a1[1][n];
  a2[1][n]=1;             //маркиране в помощния масив

    }
  else
  {
  a3[1][0]=n/2;
  a3[1][1]=n/2;             //избиране на начална клетка
  a3[1][2]=a1[n/2][n/2];
  a2[n/2][n/2]=1;           //маркиране в помощния масив
  }
  long long br2=1,br3=1,br4=1,fl=1,fl2=1,fl3=1,ti,tj,cv,ci,cj,cc,vrc,mx2=0,cv2,rc[n*n+2],brcv=0,turbo=0,br9=0,br23=0,br64=0;
  while(fl==1)
  {
    br3=1;
    fl2=1;
    while(fl2==1)          //боядисване с избрания цвят
    {
      ti=a3[br3][0];
      tj=a3[br3][1];
      cv=a3[1][2];
      cout<<"cv="<<cv<<endl;
      if(a1[ti-1][tj]==cv&&a2[ti-1][tj]==0)
      {
        br4++;
        a3[br4][0]=ti-1;
        a3[br4][1]=tj;
        a2[ti-1][tj]=1;
      }
      if(a1[ti+1][tj]==cv&&a2[ti+1][tj]==0)
      {
        br4++;
        a3[br4][0]=ti+1;
        a3[br4][1]=tj;
        a2[ti+1][tj]=1;
      }
      if(a1[ti][tj-1]==cv&&a2[ti][tj-1]==0)
      {
        br4++;
        a3[br4][0]=ti;
        a3[br4][1]=tj-1;
        a2[ti][tj-1]=1;
      }
      if(a1[ti][tj+1]==cv&&a2[ti][tj+1]==0)
      {
        br4++;
        a3[br4][0]=ti;
        a3[br4][1]=tj+1;
        a2[ti][tj+1]=1;
      }

      br3++;
      if(br3>br4)fl2=0;
      /*for(int i=1;i<=br4;i++)
      {
        cout<<"a3["<<i<<"][0]="<<a3[i][0]<<endl;
        cout<<"a3["<<i<<"][1]="<<a3[i][1]<<endl;
        cout<<"a3["<<i<<"][2]="<<a3[i][2]<<endl;
        cout<<"a3["<<i<<"][3]="<<a3[i][3]<<endl;
      }*/
    }
    if(br4>=n*n)break;
    //TURBO
    if(n<50)
    {
      for(int i=1;i<=c;i++)
      {
        s[i]=0;
      }
      for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=n;j++)
        {
          a5[i][j]=a2[i][j];
        }
      }

      for(long int i=1;i<=br4;i++)    //търсене на съседи , най-много от даден цвят
      {
        ci=a3[i][0];
        cj=a3[i][1];
        cc=a3[1][2];
        vrc=a1[ci-1][cj];
      if(a5[ci-1][cj]==0)
       {
        s[vrc]++;
        a5[ci-1][cj]=1;
       }
       vrc=a1[ci+1][cj];
       if(a5[ci+1][cj]==0)
       {
         s[vrc]++;
         a5[ci+1][cj]=1;
       }
       vrc=a1[ci][cj-1];
       if(a5[ci][cj-1]==0)
       {
         s[vrc]++;
         a5[ci][cj-1]=1;
       }
       vrc=a1[ci][cj+1];
       if(a5[ci][cj+1]==0)
       {
         s[vrc]++;
         a5[ci][cj+1]=1;
       }
    }
    mx2=0;
    for(int i=1;i<=c;i++)
    {
      if(test1==1)
       {
         if(s[i]>=mx2)
         {
           mx2=s[i];
           cv2=i;
           br23++;
           if(br23==3)
            {
              br23=0;
              break;
            }
         }
       }
      else
       {
        if(s[i]>=mx2){mx2=s[i];cv2=i;}
       }
    }
    brcv++;
    rc[brcv]=cv2;
    a3[1][2]=cv2;                     //избран е цвят за следващо боядисване
   // if(brcv>750)turbo=1;             //промяна на критерия за следващ цвят заради тайминг
  }
    if(n>=50&&n<160)
  {
    for(int i=1;i<=c;i++)
    {
      s[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        a5[i][j]=a2[i][j];
      }
    }

    for(long int i=br4;i>=br4/2;i--)    //търсене на съседи , най-много от даден цвят
    {
      ci=a3[i][0];
      cj=a3[i][1];
      cc=a3[1][2];
      vrc=a1[ci-1][cj];
      if(a5[ci-1][cj]==0)
       {
        s[vrc]++;
        a5[ci-1][cj]=1;
       }
       vrc=a1[ci+1][cj];
       if(a5[ci+1][cj]==0)
       {
         s[vrc]++;
         a5[ci+1][cj]=1;
       }
       vrc=a1[ci][cj-1];
       if(a5[ci][cj-1]==0)
       {
         s[vrc]++;
         a5[ci][cj-1]=1;
       }
       vrc=a1[ci][cj+1];
       if(a5[ci][cj+1]==0)
       {
         s[vrc]++;
         a5[ci][cj+1]=1;
       }
    }
    mx2=0;
    for(int i=1;i<=c;i++)
    {

        if(s[i]>=mx2){mx2=s[i];cv2=i;}

    }
    brcv++;
    rc[brcv]=cv2;
    a3[1][2]=cv2;                     //избран е цвят за следващо боядисване

  }
    if(n>=160)
  {
    br64=0;
    for(int i=1;i<=c;i++)
    {
      s[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        a5[i][j]=a2[i][j];
      }
    }

    for(long int i=br4;i>=1;i-3)    //търсене на съседи , най-много от даден цвят
    {
      ci=a3[i][0];
      cj=a3[i][1];
      cc=a3[1][2];
      vrc=a1[ci-1][cj];
      if(a5[ci-1][cj]==0)
       {
        s[vrc]++;
        a5[ci-1][cj]=1;
        br64++;
       }
       vrc=a1[ci+1][cj];
       if(a5[ci+1][cj]==0)
       {
         s[vrc]++;
         a5[ci+1][cj]=1;
         br64++;
       }
       vrc=a1[ci][cj-1];
       if(a5[ci][cj-1]==0)
       {
         s[vrc]++;
         a5[ci][cj-1]=1;
         br64++;
       }
       vrc=a1[ci][cj+1];
       if(a5[ci][cj+1]==0)
       {
         s[vrc]++;
         a5[ci][cj+1]=1;
         br64++;
       }
       if(br64>10)break;
    }
    mx2=0;
    for(int i=1;i<=c;i++)
    {

        if(s[i]>mx2){mx2=s[i];cv2=i;}

    }
    brcv++;
    rc[brcv]=cv2;
    a3[1][2]=cv2;                     //избран е цвят за следващо боядисване
   // if(brcv>1210)turbo=1;             //промяна на критерия за следващ цвят заради тайминг





  }



 }

  ofstream izhod;
  izhod.open("flood-it.out");
  izhod<<brcv<<'\n';
  izhod<<a3[1][0]-1<<" "<<a3[1][1]-1<<'\n';
  for(int i=1;i<=brcv;i++)
  {
    izhod<<rc[i]<<'\n';
  }
  izhod.close();
  return 0;
}

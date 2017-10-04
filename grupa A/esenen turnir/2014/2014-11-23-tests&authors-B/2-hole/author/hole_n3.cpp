// O(n^3)

#include <cstdio>

const int nmax=2000;


int wall[nmax+2][nmax+2];
int hl[nmax+2][nmax+2];
int vl[nmax+2][nmax+2];

int n;

void input()
{
  int i,j;  
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      scanf("%d", &wall[i][j]);
}

void markhl()
{
    int hlnumber = 0;
    // цикли по хоризонталните линии между редовете
    for (int i=1; i<n; i++)
    {
        // за всеки ред определя и номерира максималните хоризонтални отсечки,
        // по които може да се изрязва прозорецът
        if (wall[i][2] != wall[i+1][2])
        {
            hlnumber++;
            hl[i][1]=hlnumber;
        }
        else
            hl[i][1]=0;
        for (int j=2;j<n; j++)
        {
            if (wall[i][j]!=wall[i+1][j])
            {
                hl[i][j]=hlnumber;
            }
            else
            {
                if (wall[i][j+1] != wall[i+1][j+1])
                {
                    hlnumber++;
                    hl[i][j]=hlnumber;
                }
                else
                  hl[i][j]=0;
            }
               
        }    
        
    }
}

void markvl()
{
    int vlnumber = 0;
    // цикли по верикалните линии между стълбовете
    for (int j=1; j<n; j++)
    {
        // за всеки стълб определя и номерира максималните вертикални отсечки,
        // по които може да се изрязва прозорецът
        if (wall[2][j] != wall[2][j+1])
        {
            vlnumber++;
            vl[1][j]=vlnumber;
        }
        else
            vl[1][j]=0;
        for (int i=2;i<n; i++)
        {
            if (wall[i][j]!=wall[i][j+1])
            {
                vl[i][j]=vlnumber;
            }
            else
            {
                if (wall[i+1][j] != wall[i+1][j+1])
                {
                    vlnumber++;
                    vl[i][j]=vlnumber;
                }
                else
                  vl[i][j]=0;
            }
               
        }    
        
    }
}


int main() {
  int i, j, vbeg, s;
  int smax=0, iulmax, julmax, idrmax, jdrmax;
  input();
  markhl();
  markvl();
  
  
  for (i=1;i<n-1;i++)
    for (j=i+1;j<n;j++)
    {
        vbeg=0;
        for (int v=1;v<n;v++)
        {
            if ((vl[i][v] == vl[j][v]) && (vl[i][v]>0))
            {
               if ((hl[i][v]>0) && (hl[j][v]>0))
               {
                   if (vbeg == 0)
                     vbeg=v;
                   else
                   {
                       if ((hl[i][v] == hl[i][vbeg]) && (hl[j][v] == hl[j][vbeg]))
                       {
                           s=(j-i)*(v-vbeg);
                           if (s>smax)
                           {
                               smax=s;
                               iulmax=i+1;
                               julmax=vbeg+1;
                               idrmax=j;
                               jdrmax=v;
                           }
                       }
                       else
                         vbeg=v;
                   }  
               }
            }
        }
    }
  
  printf("%d %d %d %d %d\n",smax, iulmax, julmax, idrmax, jdrmax);  
  return 0;

}

/*
6
1 1 4 4 13 14
2 3 3 5 13 14
2 6 7 5 12 12
9 6 7 10 10 15
9 8 8 11 11 15
16 16 17 17 18 18
*/

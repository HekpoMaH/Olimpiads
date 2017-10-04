// O(n^3)

#include <cstdio>

const int nmax=2000;

int wall[nmax+2][nmax+2];
int hl[nmax+2][nmax+2];
int vl[nmax+2][nmax+2];

int n;
int asmax, csmax, ciulmax, cjulmax, cidrmax, cjdrmax;

void markhl()
{
    int hlnumber = 0;
    // ����� �� �������������� ����� ����� ��������
    for (int i=1; i<n; i++)
    {
        // �� ����� ��� �������� � �������� ������������ ������������ �������,
        // �� ����� ���� �� �� ������� ����������
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
    // ����� �� ����������� ����� ����� ����������
    for (int j=1; j<n; j++)
    {
        // �� ����� ����� �������� � �������� ������������ ���������� �������,
        // �� ����� ���� �� �� ������� ����������
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


int main(int argc, char * argv[]) {
  int i, j;
  FILE *wsol;
  FILE *wout;
  FILE *win;
  
  win=fopen(argv[1],"r");
  wsol=fopen(argv[3],"r");
  wout=fopen(argv[2],"r");
  
  if (win==NULL)
    {   printf("0\nCannot open in file\n");
        return 1;
    }
    if (wout==NULL)
    {   printf("0\nCannot open out file\n");
        return 1;
    }
    if (wsol==NULL)
    {   printf("0\nCannot open sol file\n");
        return 1;
    }
   
  fscanf(win,"%d",&n);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      fscanf(win,"%d", &wall[i][j]);
  fscanf(wout,"%d %d %d %d %d", &csmax, &ciulmax, &cjulmax, &cidrmax, &cjdrmax);    
  fscanf(wsol,"%d",&asmax);  
  markhl();
  markvl();
   
  if (csmax != asmax)
  {
      // �� � ����� ����������� ���������� ���� �� �������������:
      // ���� ��������� �� ������ �������
      printf("%i\nWrong answer\n", 0);
      return 0;
  }
  else
  {
      // ����������� ���������� ���� � ����� - ������ �� �� ������� ����
      // ������������ � ����������� �� ���������� �� �����������
      // ���������� �� ����� ��� � ����� ����� ���� ������������� ��������� �� ��������.
      // ����� �� ��������� ���� �� �� ������ ��� �� ������� ������ �� �������
      if ((ciulmax<2) || (cjulmax<2) || (cidrmax>n-1) || (cjdrmax>n-1))
      {
         // �������������� �� ������ ��� ������� ������ �� �������:
         // ���� ������ �������
         printf("%i\nWrong answer\n", 0);
         return 0;                                                                                                                                                            
      }
      else
      {
         if ((hl[ciulmax-1][cjulmax-1]==0) || (vl[ciulmax-1][cjulmax-1]==0)||
             (hl[ciulmax-1][cjdrmax]==0) || (vl[ciulmax-1][cjdrmax]==0) ||
             (hl[cidrmax][cjulmax-1]==0) || (vl[cidrmax][cjulmax-1]==0) ||
             (hl[cidrmax][cjdrmax])==0 || (vl[cidrmax][cjdrmax]==0) ||
             (hl[ciulmax-1][cjulmax-1] != hl[ciulmax-1][cjdrmax]) ||
             (hl[cidrmax][cjulmax-1] != hl[cidrmax][cjdrmax]) ||
             (vl[ciulmax-1][cjulmax-1] != vl[cidrmax][cjulmax-1]) ||
             (vl[ciulmax-1][cjdrmax] != vl[cidrmax][cjdrmax]))  
             {
                 // ����� �� �������� �� �������� ����������� �����
                 // ���� ������ �������
                 printf("%i\nWrong answer\n", 0);
                 return 0;
             }
             else
             {
                 //��������� � �����
                 // ���� ������� �� �����
                 printf("%s\nAccepted\n", argv[4]);
             }
      }
       
  }
  return 0;

}



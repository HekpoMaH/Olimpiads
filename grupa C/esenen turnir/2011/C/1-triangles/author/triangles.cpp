//Task: triangles
//Author: Plamenka Hristova

#include <cstdlib>
#include <iostream>
#include <math.h>

#define MAXPNT 26

using namespace std;

typedef struct {
                char PtName;
                int X;
                int Y;
            }Point;
Point Pnt[MAXPNT];

 // Ако a, b, c са страни на  триъгълник - 1 иначе - 0
 int IsTriangle(int a, int b, int c)
               {
                // if((a<b+c)&&(b<a+c)&&(c<a+b)) return 1; else return 0;
                return  (a<b+c)&&(b<a+c)&&(c<a+b) ? 1 : 0;
               }

int main()
    {
    int N, i, j, k, key=0;
    float a, b, c;

    cin >> N;
    for(i=0; i<N; i++)
        cin>>Pnt[i].PtName>>Pnt[i].X>>Pnt[i].Y;

    for(i=0; i<N;i++)
       for(j=i+1; j<N; j++)
          for(k=j+1; k<N; k++)
             {
              a = sqrt((Pnt[i].X-Pnt[j].X)*(Pnt[i].X-Pnt[j].X)+(Pnt[i].Y-Pnt[j].Y)*(Pnt[i].Y-Pnt[j].Y));
              b = sqrt((Pnt[j].X-Pnt[k].X)*(Pnt[j].X-Pnt[k].X)+(Pnt[j].Y-Pnt[k].Y)*(Pnt[j].Y-Pnt[k].Y));
              c = sqrt((Pnt[k].X-Pnt[i].X)*(Pnt[k].X-Pnt[i].X)+(Pnt[k].Y-Pnt[i].Y)*(Pnt[k].Y-Pnt[i].Y));
              if( IsTriangle(a, b, c))
                {
                   key=1;
                   cout <<Pnt[i].PtName<<" "<< Pnt[j].PtName<<" "<< Pnt[k].PtName<<endl;
                }
            }

    if(key==0)
          cout << "No triangles." << endl;
    return 0;
   }

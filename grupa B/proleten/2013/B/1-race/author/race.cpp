//Task Race
// Author Pano Panov
#include <iostream>

#define MAXARROWS 100
#define MAXPOINTS 50

using namespace std;

int PtsNum,ArrNum;
int CurrArr, CurrPnt;
int UnAvoidPntNum;

int Arrows[MAXARROWS][2];
bool Unavoid[MAXPOINTS];
bool Reachable[MAXPOINTS];

void init()
 {
  PtsNum = 1;
  ArrNum = 0;
  UnAvoidPntNum = 0;
  for(CurrPnt = 0; CurrPnt < MAXPOINTS; CurrPnt++)
    {
     Unavoid[CurrPnt] = false;
    }
 }

void ReadInput()
     {
      int num;
      cin>>num;
      while(!(num == -1))
           {
            if(num == -2)
              {
                PtsNum++;
              }
            else
              {
               Arrows[ArrNum][0] = PtsNum-1;
               Arrows[ArrNum][1] = num;
               ArrNum++;
              }
            cin >> num;
           }// End of while
     }

void PrnOutput()
     {
      cout << UnAvoidPntNum;
      for(CurrPnt=1; CurrPnt < PtsNum-1; CurrPnt++)
         {
          if(Unavoid[CurrPnt]) cout << ' ' << CurrPnt;
         }
      cout << endl;
     }

void find_Reachable(int CurrPnt)
     {
      int point;
      bool ready;

      for(point=1; point < PtsNum; point++)
          Reachable[point] = false;
      Reachable[0] = true;
      ready = false;
      while(!ready)
           {
             ready = true;
             for(CurrArr = 0; CurrArr < ArrNum; CurrArr++)
                if(Reachable [Arrows[CurrArr][0]] &&
                  !(Reachable [Arrows[CurrArr][1]]) &&
                 (Arrows[CurrArr][1] != CurrPnt))
                 {
                  Reachable[Arrows[CurrArr][1]] = true;
                  ready = false;
                 }
           }
     }
void compute_results()
     {
      for(CurrPnt=1;  CurrPnt < PtsNum-1; CurrPnt++)
         {
          find_Reachable(CurrPnt);
          if(!Reachable[PtsNum-1])
            {
             Unavoid[CurrPnt] = true;
             UnAvoidPntNum++;
            }
         }
      }

int main()
{
    init();
    ReadInput();
    compute_results();
    PrnOutput();
    return 0;
}

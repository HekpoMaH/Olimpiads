// Task - mtcd
// Author - Pano Panov
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <cstring>

#define PNTMAX 256         // Max number of Navigation Points
#define FLIGHTMAX 256      // Max number of Activation messages
#define CONFLICTSMAX 256   // Max length of Conflicts detected

using namespace std;
typedef struct
   {
    char PointName[4];     // Name of Navigation Point
    double X;              // X Coord
    double Y;              // Y Coord
   } NavPoint;
NavPoint pnt[PNTMAX];

typedef struct
   {
    int  Status;          // Flight Status 0 - Pending; 1 - active; 2 - archive;
    char CallSign[7];     // Name of Flight
    int  EntryPntIdx;     // Entry Point Index
    int EntryTime;       // Entry Time sec.
    int  ExitPntIdx;      // Exit Point Index
    int ExitTime;        // Exit Time sec.
    double speed;         // Speed km/h
    double Xpos;          // Current position X
    double Ypos;          // Current position Y
    double dx;            // Step km/min X
    double dy;            // Step km/min Y
    double EntryLevel;    // Flight Level meters
   } ActMsg;
ActMsg flts[FLIGHTMAX];   // Fligths list

typedef struct
   {
    char CallSign1[7];     // First Conflicted Plane
    char CallSign2[7];     // Second Conflicted Plane
    int  tm;               // When the conflict began sec
   } ConflictsQueue;
ConflictsQueue cnf[CONFLICTSMAX]; // Conflicts Queue
int cnfptr=0;

int N, M;                  // Num of Nav Points
double CtrlDist;           // Num of Act Messages
int StartTime = 1450;      // Number greater then number of minutes per day
int FinishTime = 0;        // Time to Finish simulation
int narch=0, nact=0, npend=0, ResCount=0; // Number of archived, active and pending Flights

// Search Point by name
int FindPnt(char *nm)
    {
     int i;
     for(i=0; i<N; i++)
        {
         if(strncmp(nm, pnt[i].PointName,3)==0) return i;
        }
     return -1;
    }
// Every minute retrive Flight list and recalculate each status of Flights
int ExtractFlight(int now)
    {
     int i;
     npend = nact = narch = 0;
     for(i=0; i<M; i++)
        {
         switch(flts[i].Status)
               {
                case 0: // Pending to Active If now is the time
                       if(now>=flts[i].EntryTime)
                         {
                          flts[i].Status = 1;
                          nact++;
                         }
                       else npend++;
                       break;
                case 1: // Active Flights prediction of trajectory, archive if it is necessary
                       if(now>flts[i].ExitTime)
                         {
                          flts[i].Status = 2;
                          narch++;
                         }
                       else
                         nact++;
                       break;
                case 2: // Archive status
                       narch++;
                       break;
               } // End of switch
         }
     return nact; // Num of active Flights
    }
// Data Entry Routine
int ReadData()
    {
     int i, k;
     float wx, wy;
     cin >> N >> M >> CtrlDist;

     for(i=0; i<N; i++) cin >> pnt[i].PointName >> pnt[i].X >> pnt[i].Y;
     //Act message template: BAW777 GOL 1400 640 12000 SOM
     for(i=0; i<M; i++)
        {
         char pin[4], pout[4];
         cin>>flts[i].CallSign>>pin>>k>>flts[i].speed>>flts[i].EntryLevel>>pout;
         flts[i].EntryPntIdx = FindPnt(pin);
         flts[i].ExitPntIdx = FindPnt(pout);
         flts[i].EntryTime=k/100*60+k%100;
         flts[i].Xpos = pnt[flts[i].EntryPntIdx].X;
         flts[i].Ypos = pnt[flts[i].EntryPntIdx].Y;
         wx=(float )(-pnt[flts[i].EntryPntIdx].X+pnt[flts[i].ExitPntIdx].X);
         wy=(float )(-pnt[flts[i].EntryPntIdx].Y+pnt[flts[i].ExitPntIdx].Y);
         // Time = Distance / speed
         flts[i].ExitTime=(int )(60.0*sqrt(wx*wx+wy*wy)/(float )flts[i].speed+0.5);
         flts[i].Status=0; // --> Pending
         // Steps per minute
         flts[i].dx = wx/flts[i].ExitTime;
         flts[i].dy = wy/flts[i].ExitTime;
         flts[i].ExitTime += flts[i].EntryTime;
         // Luck for time frame of simulation
         if(StartTime > flts[i].EntryTime) StartTime = flts[i].EntryTime;
         if(FinishTime < flts[i].ExitTime) FinishTime = flts[i].ExitTime;
        }
       FinishTime += 2;
     return 0;
    }
// Save conflict in stack if it is arise now
int MarkConflict(int fp1, int fp2, int ntm)
    {
     int i, j=0;
     bool flg=true;
     for(i=0; i<cnfptr; i++)
        {
         if((strcmp(cnf[i].CallSign1, flts[fp1].CallSign)==0) &&
            (strcmp(cnf[i].CallSign2, flts[fp2].CallSign)==0))
           {
            if(ntm-1 > cnf[i].tm){ResCount++; j=1;}
            flg = false;
            cnf[i].tm = ntm;
           }
		}
     if(flg)
       {
        strcpy(cnf[cnfptr].CallSign1, flts[fp1].CallSign);
        strcpy(cnf[cnfptr].CallSign2, flts[fp2].CallSign);
        cnf[cnfptr++].tm = ntm;
        ResCount++;
        j=1;
       }
     return j;
    }
// Check for conflicts
int Conflicts(int now)
    {
     int i, j;
     double w1,w2,dist;
     for(i=0; i<M-1; i++)
        {
         if(flts[i].Status==1)
           {// Active only
            for(j=i+1; j<M; j++)
               {
                if(flts[j].Status==1)
                  { // Active only
                   if(fabs(flts[i].EntryLevel-flts[j].EntryLevel)<=1000.0)
                     {
                      w1=  flts[i].Xpos-flts[j].Xpos;
                      w2=  flts[i].Ypos-flts[j].Ypos;
                      dist = sqrt(w1*w1+w2*w2);
                      if(dist*1000.0 < CtrlDist) MarkConflict(i, j, now);
                     }
                  }
               }

           }
        }
     for(i=0; i<M; i++)
        {
         if(flts[i].Status==1)
           {
            flts[i].Xpos += flts[i].dx;
            flts[i].Ypos += flts[i].dy;
           }
        }

     return 0;
    }


int main()
{
    int i, k;

    ReadData();
    for(i=StartTime; i<=FinishTime; i++)
       {
        if((k=ExtractFlight(i)) == 0) continue;
        Conflicts(i);
       }
    cout<<ResCount<<endl;
    return 0;
}

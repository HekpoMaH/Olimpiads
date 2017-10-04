// Copyright(c) 1996 Leendert Ammeraal. All rights reserved.
// This program text occurs in Chapter 9 of
//
//    Ammeraal, L. (1996) Algorithms and Data Structures in C++,
//       Chichester: John Wiley.

/* cpm: Critical path method
   The program asks for an input file, containing
   a line for each activity with two (integer)
   event numbers, a duration (integer), and an
	optional description. The range of the event
	numbers influences the amount of memory needed.
	Apart from this, there are no limitations
	imposed on the number of events or on the way
	they are numbered, nor are there any restrictions
   on the number of activities or on their order in
   the input file, except for memory limitations of
   the machine on which the program runs.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct activity{int num, dur; activity *next;};

class project {
public:
   project(){tMax = 0;}
   int min, n; // Minimum event number and n = max - min + 1
   void SetRange(const char *fname);
   void build(const char *fname);
   void StartNodes();
   void EarliestEventTime();
   void inverted(const char *fname);
   void EndNodes();
   void LatestEventTime();
   void output(const char *fname);
private:
   struct event{int count, ee, le; activity *link;} *a;
   int tMax;
   enum {nil=-1, absent=-2};
   int start; // Start of simulated linked list
              // for nodes without a predecessor
   void SkipRestLine(ifstream &file);
};

void project::SkipRestLine(ifstream &file)
{  char ch;
   do file.get(ch); while (!file.fail() && ch != '\n');
}

void project::SetRange(const char *fname)
{  ifstream file(fname, ios::in );
   if (file.fail())
   {  cout << "Cannot open input file.\n";
      exit(1);
   }
   int max, x, first=1, jRead = 1;
   for (;;)
   {  file >> x;
      jRead = !jRead; // x is either i or j of <i, j>
      if (jRead) SkipRestLine(file);
      if (file.fail()) break;
      if (first){min = max = x; first = 0;} else
      if (x < min) min = x; else
      if (x > max) max = x;
   }
   file.close();
   n = max - min + 1;
}

void project::build(const char *fname)
{  int i, j, I, J, d;
   activity *p;
   a = new event[n];
   for (i=0; i<n; i++)
   {  a[i].count = absent; a[i].ee = 0; a[i].link = 0;
   }
   ifstream file(fname, ios::in );
   for (;;)
   {  file >> I >> J >> d;
      SkipRestLine(file);
      if (file.fail()) break;
      i = I - min; j = J - min;
      if (a[i].count == absent) a[i].count = 0;
      if (a[j].count == absent) a[j].count = 0;
      p = new activity;
      p->num = j; p->dur = d;
      p->next = a[i].link;
      a[i].link = p;
      a[j].count++;
   }
   file.close();
}

void project::StartNodes()
{  int i;
   // Set up simulated linked list of start nodes:
   start = nil;
   for (i=0; i<n; i++)
      if (a[i].count == 0){a[i].count = start; start = i;}
}

void project::EarliestEventTime()
{  int i, j, k, t1;
   activity *p;
   for (i=0; i<n; i++)
   {  while (a[i].count == absent) i++;
      if (start == nil)
      {  cout << "There is a cycle.\n"; return;
      }
      /*  Take an event from the stack, and decrease
          the in-degree of all its immediate
          successors by 1. As soon as the updated
          in-degree of a successor is zero, place it
          on the stack and dispose of the (activity)
          node in the adjacency list.
      */
      j = start; start = a[j].count;
      for (;;)
      {  p = a[j].link;
         if (p == 0) break;
         k = p->num;
         a[k].count--;
         t1 = a[j].ee + p->dur;
         if (t1 > a[k].ee) a[k].ee = t1;
         if (t1 > tMax) tMax = t1;
         if (a[k].count == 0)
         {  a[k].count = start; start = k;
         }
         a[j].link = p->next;
         delete p;
         // In the adjacency list we have disposed of a node
         // that we don't need any longer.
      }
   }
}

void project::inverted(const char *fname)
{  int i, j, I, J, d;
   activity *p;
   for (j=0; j<n; j++)
      if (a[j].count != absent)
      {  a[j].le = tMax; a[j].count = 0; a[j].link = 0;
      }
   ifstream file(fname, ios::in );
   for (;;)
   {  file >> I >> J >> d;
      SkipRestLine(file);
      if (file.fail()) break;
      i = I - min; j = J - min;
      p = new activity;
      p->num = i; p->dur = d;
      p->next = a[j].link;
      a[j].link = p;
      a[i].count++;
   }
   file.close();
}

void project::EndNodes()
{  start = nil;
   for (int j=0; j<n; j++)
      if (a[j].count == 0){a[j].count = start; start = j;}
}

void project::LatestEventTime()
{  int i, j, k, t1;
   activity *p;
   for (j=0; j<n; j++)
   {  while (a[j].count == absent) j++;
      i = start; start = a[i].count;
      for (;;)
      {  p = a[i].link;
         if (p == 0) break;
         k = p->num;
         a[k].count--;
         t1 = a[i].le - p->dur;
         if (t1 < a[k].le) a[k].le = t1;
         if (a[k].count == 0)
         {  a[k].count = start; start = k;
         }
         a[i].link = p->next;
         delete p;
      }
   }
}

void project::output(const char *fname)
{  char descript[80];
   int i, j, I, J, d, est, lct, ect, lst, slack;
   cout << "Output:\n\n";
   cout << "  I   J  DUR   EST  LST   ECT  LCT  "
           "SLACK     DESCRIPTION\n\n";
   ifstream file(fname, ios::in );
   for (;;)
   {  file >> I >> J >> d;
      if (file.fail()) break;
      file.getline(descript, 80);
      i = I - min; j = J - min;
      est = a[i].ee; // Earliest start time
      lct = a[j].le; // Latest completion time
      ect = est + d; // Earliest completion time
      lst = lct - d; // Latest start time
      slack = lst - est;
      cout << setw(3) << I << " "
           << setw(3) << J << " "
           << setw(4) << d << " "
           << setw(5) << est << " "
           << setw(4) << lst << " "
           << setw(5) << ect << " "
           << setw(4) << lct << " "
           << setw(6) << slack << " "
           << (slack ? "   " : "<--")
           << descript << endl;
   }
   file.close();
}

int main()
{  project g;
   char fname[50];
   cout << "Input file: ";
   cin >> setw(50) >> fname;
   g.SetRange(fname);     // Find range of event numbers
   g.build(fname);        // Build adjacency lists
   g.StartNodes();        // Form linked list of start nodes
   g.EarliestEventTime(); // Find ee for each node
   g.inverted(fname);     // Build inverted adjacency lists
   g.EndNodes();          // Form linked stack of end nodes
   g.LatestEventTime();   // Find le for each node
   g.output(fname);       // Produce resulting table
   return 0;
}


#include <iostream>
using namespace std;
int main()
{int k,digit,count,module,answer_digit,answer_count;
    cin>>k;
   answer_count=10000;
   for (digit=1; digit<=9; digit++)
   {
      module=0;
      for (count=1; count<=1000; count++)
        {
         module=(module*10+digit)%k;
         if (module==0)
            if (count<answer_count)
              {
               answer_digit=digit;
               answer_count=count;
              }
         }
   }

   if (answer_count==10000)
      cout<<"Impossible"<<endl;
   else
      cout<<answer_digit<<" "<<answer_count<<endl;
}

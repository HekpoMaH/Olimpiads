#include <iostream>
#include <cstring>

using namespace std;

#define MAX_LEN 26

char inp[MAX_LEN];

int num = 0, nexs = 0, fective_len;

class Operand {
      public:
       Operand() {
                 sign = '+';
       }
       char sign;
};

Operand* getOp();

void eval() {
    Operand* op1 = getOp();
    char man = inp[nexs++];
    Operand* op2 = getOp();
    if (op2 == NULL)
       return;
    do {
          if (man == '+') {
                  if (op1->sign == '+') {
                     num++;
                    // cout << "num++\n";
                  }
          }
          else if (man == '-') {
               if (op1->sign == '+') {
                  num++;
                 // cout << "num++\n";
               }
               op2->sign = '-';
          }
          else if (man == '*') {
               if (op1->sign == '+')
                  num++;
          }
          else if (man == '/') {
               if (op1->sign == '*')
                  num++;
               op2->sign = '/';
          }
          delete op1;
          op1 = op2;
          op2 = getOp();
          //std::cout << nexs;
    } while (nexs < fective_len);
}

int main() {
    
    std::cin >> inp;
    
    fective_len = strlen(inp);
    eval();
    int tmp;
    std::cout << num;
}

Operand* getOp() {
         Operand *result = new Operand();
         char sign = inp[nexs++];
         if (sign == '\0')
            return NULL;
         if (sign == '(') {
            eval();
            sign = inp[nexs+=1];
         }
         sign = inp[nexs+1];
         if (sign == '*') {
               result->sign='*';
               nexs++;
               getOp();
               num++;
         }
         return result;
}

#include <iostream>
#include <string>
#include <strstream>
#include <queue>
using namespace std;
string str;

string IntToStr ( int a )
{
  strstream buf;
  string result;
  buf << a;
  buf >> result;
  return result;
}
bool StrFind ( const string & a, char c )
{
  for ( unsigned short i = 0; i < a.length (); i++ )
    if ( a [ i ] == c )
      return true;
  return false;
}

int main ()
{
  cin >> str;

  for ( short i = 1, skobi = 0; i < str.length (); i++ )
  {
    if ( str[i] == '*' )
    {
      if ( str [ i-1 ] >= '0' && str [ i-1 ] <= '9' && str [ i+1 ] >= '0' && str [ i+1 ] <= '9' )
      {
        str = str.substr( 0, i-1 ) + "(" + str.substr( i-1, 3 ) + ")" + str.substr( i+2, str.length()+3 );
        i++;
      }
      else
      {
        short j = i - 1, k = i + 1;
        if ( ! ( str [ j ] >= '0' && str [ j ] <= '9' ) )
        {
          skobi = -1;
          for ( j--; j >= 0; j-- )
          {
            if ( str [j] == ')')
              skobi--;
            else if ( str [j] == '(')
              skobi++;
            if ( ! skobi )
              break;
          }
        }
        if ( ! ( str [ k ] >= '0' && str [ k ] <= '9' ) )
        {
          skobi = 1;
          for ( k++; k < str.length(); k++ )
          {
            if ( str [k] == ')')
              skobi--;
            else if ( str [k] == '(')
              skobi++;
            if ( ! skobi )
              break;
          }
        }
        str = str.substr( 0, j ) + "(" + str.substr( j, k - j + 1 ) + ")" + str.substr( k + 1, str.length()+3 );
        i++;
      }
    }
  }
  while ( StrFind ( str, '(' ) )
  {
  for ( short i = 1, j, k; i < str.length (); i++ )
  {
    if ( str [ i ] == '*' && str [ i-1 ] >= '0' && str [ i-1 ] <= '9' && str [ i+1 ] >= '0' && str [ i+1 ] <= '9' )
    {
      for ( j = i - 1; j >= 0; j-- )
      {
        if ( ! ( str [ j ] >= '0' && str [ j ] <= '9' ) )
          break;
      }
      for ( k = i + 1; k < str.length(); k++ )
      {
        if ( ! ( str [ k ] >= '0' && str [ k ] <= '9' ) )
          break;
      }
      j++; k--;
      long value = atol ( string ( str.substr ( j, i-j ) ).c_str() ) * atol ( string ( str.substr ( i+1, k-i ) ).c_str() );
      str = str.substr ( 0, j - 1 ) + IntToStr ( value ) + str.substr ( k + 2, str.length()+3 );
    }
  }
  }



  if ( str [ 0 ] == '-' )
    str = "0" + str;

  queue <long> num; queue <char> oper;


  for ( short i = 0, k; i < str.length (); i++ )
  {
    if ( str [ i ] >= '0' && str [ i ] <= '9' )
    {
      for ( k = i; k < str.length(); k++ )
      {
        if ( ! ( str [ k ] >= '0' && str [ k ] <= '9' ) )
          break;
      }
      k--;
      num.push ( atol ( string ( str.substr ( i, k-i+1 ) ).c_str() ) );
      i = k;
    }
    else
      oper.push ( str [ i ] );
  }


  long temp_l;
  while ( num.size() != 1 )
  {
    if ( oper.front() == '+' )
    {
      temp_l = num.front();
      num.pop ();
      temp_l += num.front();
      num.front () = temp_l;
      oper.pop();
    }
    if ( oper.front() == '-' )
    {
      temp_l = num.front();
      num.pop ();
      temp_l -= num.front();
      num.front () = temp_l;
      oper.pop();
    }
  }

  cout << num.front () << endl;









  return 0;
}

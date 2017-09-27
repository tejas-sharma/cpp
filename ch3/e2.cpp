#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;

template <class T>
string to_tuple_string_aux(const T & item)
{
  cout << __PRETTY_FUNCTION__ << endl;
  stringstream ss;
  ss << item;
  return ss.str();
}

template <class T,class ...P>
string to_tuple_string_aux(T first, P... items)
{
  cout << __PRETTY_FUNCTION__ << endl;
  stringstream ss;
  ss << first << "," << to_tuple_string_aux(items...);
  return ss.str();
}

template <class ...P>
string to_tuple_string(P... items)
{
  stringstream ss;
  ss << "(" << to_tuple_string_aux(items...) << ")" << endl;
  return ss.str();
}

int main(int argc, char ** argv) 
{
  cout << to_tuple_string(1,2,3) << endl;
  return 0;
}

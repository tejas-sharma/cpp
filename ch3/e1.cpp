#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
string to_string(const T & item)
{
  std::stringstream ss;
  ss << item;
  return ss.str();
}

int main(int argc, char ** argv) 
{
  int i = { 10 };
  double j = { 3.14 };
  cout << to_string(i) << endl;
  cout << to_string(j) << endl;
}

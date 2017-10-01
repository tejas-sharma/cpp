#include <iostream>
#include <string>
using namespace std;

template <class T, size_t N>
size_t array_size(T (&arr)[N])
{
  return N;
}

int main(int argc, char** argv) 
{
  int foo[3] = { 1 , 2, 3};
  string bar[5] = { "a", "b", "c", "d", "e" };
  cout << array_size(foo) << endl;
  cout << array_size(bar) << endl;
  return 1;
}

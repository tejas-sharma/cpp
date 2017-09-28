#include <iostream>
#include "stack.tpp"

using namespace std;

int main(int argc, char ** argv) 
{
  Stack<int, 3> s;
  s.push(1);
  cout << s.top() << endl;
  s.push(2);
  cout << s.top() << endl;
  s.push(3);
  cout << s.top() << endl;
  cout << s.push(4) << endl;
  s.clear();
  cout << s.size() << endl;
  return 0;
}

#include <iostream>
#include "stack.tpp"

using namespace std;

int main(int argc, char ** argv) 
{
  Stack<int, 3> s;
  s.push(1);
 // cout << s.top() << endl;
  s.push(2);
  //cout << s.top() << endl;
  s.push(3);


  cout << "hi" << endl;
  cout << "Printing stack" << endl;
  auto itr = s.begin();
  for (auto i : s) 
  {
    cout << i << endl;
  }
  for (auto iter = s.begin(); iter != s.end(); ++iter)
  {
    cout << *iter << endl;
  }
  //cout << s.top() << endl;
  //cout << s.push(4) << endl;
  cout << "moving" << endl;
  auto s2 = std::move(s);
  for (auto i : s2) 
  {
    cout << i << endl;
  }

  cout << "boolean specialization" << endl;

  cout << endl;
  Stack<bool, 10> s3;
  s3.push(true);
  s3.push(false);
  s3.push(true);
  s3.push(false);
  s3.push(true);
  s3.push(false);
  s3.push(true);
  s3.push(false);
  s3.push(true);
  s3.push(false);
  for (auto b : s3) 
  {
    cout << b << endl;
  }
  return 0;
}

#include <utility>
#include <memory>
#include <iostream>
#include <string>

using namespace std;

struct Foo
{
  string s;
  Foo(const string& s) : s(s) { cout << "constructor" << endl; }
  Foo(string&& s) : s(std::move(s)) { cout << "move constructor" << endl; }
};

template <class T, class ...P>
unique_ptr<T> make_unique(P&&... params)
{
  return unique_ptr<T>(new T(std::forward<P>(params)...));
}

int main(int argc, char** argv) 
{
  using ::make_unique;
  auto u1 = make_unique<Foo>("Hello World");
  string s1 = "Hello World";
  auto u2 = ::make_unique<Foo>(s1); // :: is needed because of ADL
  //auto u3 = std::make_unique<Foo>(s1);
  return 0;
}

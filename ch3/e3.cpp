#include <iostream>
#include <vector>
#include <utility>
#include <memory>

using namespace std;

template <class T, size_t N>
class Stack
{
  private:
    const unsigned int _size;
    array<T, N> _data;
  public:
    Stack();
};

template <class T, size_t N>
Stack<T, N>::Stack()
{
}

int main(int argc, char ** argv) 
{
  return 0;
}

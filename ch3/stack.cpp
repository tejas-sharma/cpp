#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <array>
#include <stdexcept>

using namespace std;

template <class T, size_t N>
class Stack
{
  private:
    array<T, N> _data;
    unique_ptr<size_t> _top;
    bool _init;
  public:
    Stack();
    T& top();
    const T& top() const;
    bool pop();
    bool push(const T&);
    void clear();
    size_t size() const;
    bool full() const;
    bool empty() const;
};

template <class T, size_t N>
Stack<T, N>::Stack() 
{
}

template<class T, size_t N>
bool Stack<T, N>::full() const
{
  return _top && *_top == N-1;
}

template<class T, size_t N>
bool Stack<T, N>::empty() const 
{
  return !_top;
}

template<class T, size_t N>
size_t Stack<T,N>::size() const
{
  return !_top ? 0 : *_top + 1;
}

template <class T, size_t N>
T& Stack<T, N>::top()
{
  return const_cast<T&>(static_cast<const Stack<T,N>*>(this)->top());
}

template <class T, size_t N>
const T& Stack<T, N>::top() const
{
  if (empty()) throw runtime_error("Called top() on an empty stack");
  return _data[*_top];
}

template <class T, size_t N>
bool Stack<T, N>::pop()
{
  if (empty()) return false;
  if (*_top == 0) 
  {
    _top.reset();
  }
  else 
  {
    --*_top;
  }
  return true;
}

template <class T, size_t N>
bool Stack<T, N>::push(const T& item)
{
  if (full()) return false;
  size_t insertIdx {0};
  if (!_top) 
  {
    _top.reset(new size_t{0});
  }
  else 
  {
    insertIdx = ++(*_top);
  }
  
  _data[insertIdx] = item;
  return true;
}

template <class T, size_t N>
void Stack<T, N>::clear()
{
  _top.reset();
}

int main(int argc, char ** argv) 
{
  Stack<int, 3> s;
  s.push(1);
  cout << s.top() << endl;
  s.push(2);
  s.push(3);
  cout << s.top() << endl;
  cout << s.push(4) << endl;
  s.clear();
  cout << s.size() << endl;
  return 0;
}

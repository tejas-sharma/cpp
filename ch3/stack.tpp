#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <array>
#include <stdexcept>

template <class T, size_t N>
class Stack
{
  private:
    std::array<T, N> _data;
    std::unique_ptr<size_t> _top;
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
Stack<T, N>::Stack() : _top(std::make_unique<size_t>(0))
{
}

template<class T, size_t N>
bool Stack<T, N>::full() const
{
  return *_top == N;
}

template<class T, size_t N>
bool Stack<T, N>::empty() const 
{
  return *_top == 0;
}

template<class T, size_t N>
size_t Stack<T,N>::size() const
{
  return *_top;
}

template <class T, size_t N>
T& Stack<T, N>::top()
{
  return const_cast<T&>(static_cast<const Stack<T,N>*>(this)->top());
}

template <class T, size_t N>
const T& Stack<T, N>::top() const
{
  if (empty()) throw std::runtime_error("Called top() on an empty stack");
  return _data[*_top-1];
}

template <class T, size_t N>
bool Stack<T, N>::pop()
{
  if (empty()) return false;
  --*_top;
  return true;
}

template <class T, size_t N>
bool Stack<T, N>::push(const T& item)
{
  if (full()) return false;
  _data[(*_top)++] = item;
  return true;
}

template <class T, size_t N>
void Stack<T, N>::clear()
{
  *_top = 0;
}

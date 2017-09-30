#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <array>
#include <stdexcept>
template <class T>
class StackIterator 
{
};

template <class T, size_t N>
class Stack
{
  private:
    std::array<T, N> _data; 
    std::unique_ptr<size_t> _top;
    class StackIterator 
    {
      private:
        Stack<T, N>* _stack;
        size_t _idx;
      public:
        StackIterator(Stack<T, N>* stack, size_t idx);
        T& operator*();
        const T& operator*() const;
        StackIterator operator++();
        bool operator!=(const StackIterator& other) const;
    };
  public:
    using iterator = StackIterator;
    using const_iterator = const StackIterator;
    Stack();
    Stack(Stack&& );
    Stack& operator=(Stack&&);
    T& top();
    const T& top() const;
    bool pop();
    bool push(const T&);
    void clear();
    size_t size() const;
    bool full() const;
    bool empty() const;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

template <class T, size_t N>
Stack<T, N>::Stack() : _top(std::make_unique<size_t>(0))
{
}

template <class T, size_t N>
Stack<T, N>::Stack(Stack<T, N>&& other) : _top(std::move(other._top)), _data(std::move(other._data))
{
}

template <class T, size_t N>
Stack<T, N>& Stack<T, N>::operator=(Stack<T, N>&& other)
{
  if (this != &other)
  {
    _top = std::move(other._top);
    _data = std::move(other._data);
  }
  return *this;
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

template <class T, size_t N>
typename Stack<T, N>::iterator Stack<T, N>::begin()
{
  return StackIterator{this, *_top};
}

template <class T, size_t N>
typename Stack<T, N>::iterator Stack<T, N>::end()
{
  return StackIterator { this, 0 };
}

template <class T, size_t N>
typename Stack<T, N>::const_iterator Stack<T, N>::begin() const
{
  return StackIterator{this, *_top};
}

template <class T, size_t N>
typename Stack<T, N>::const_iterator Stack<T, N>::end() const
{
  return StackIterator { this,  0};
}

template <class T, size_t N>
T& Stack<T, N>::StackIterator::operator*()
{
  return _stack->_data[_idx-1];
}

template <class T, size_t N>
typename Stack<T,N>::StackIterator Stack<T, N>::StackIterator::operator++() 
{
  --_idx;
}

template <class T, size_t N>
bool Stack<T, N>::StackIterator::operator!=(const Stack<T,N>::StackIterator &other) const
{
  return _stack != other._stack || _idx != other._idx;
}

template <class T, size_t N>
const T& Stack<T, N>::StackIterator::operator*() const
{
  return _stack->_data[_idx-1];
}

template <class T, size_t N>
Stack<T, N>::StackIterator::StackIterator(Stack<T, N>* stack, size_t idx) : _stack(stack), _idx(idx)
{
}


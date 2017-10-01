#include <iostream>
#include <vector>
#include <utility>
#include <memory>
#include <array>
#include <stdexcept>

template <size_t N>
class Stack<bool, N>
{
  private:
    unsigned char _data[(N + 7)/8];
    std::unique_ptr<size_t> _top;
    class StackIterator 
    {
      private:
        Stack<bool, N>* _stack;
        size_t _idx;
      public:
        StackIterator(Stack<bool, N>* stack, size_t idx);
        bool operator*();
        const bool operator*() const;
        StackIterator operator++();
        bool operator!=(const StackIterator& other) const;
    };
    struct BoolProxy
    {
      unsigned char& data;
      unsigned char mask;
      BoolProxy(unsigned char& data, size_t offset);
      operator bool() const;
      BoolProxy& operator=(bool value);
    };
  public:
    using iterator = StackIterator;
    using const_iterator = const StackIterator;
    Stack();
    Stack(Stack&& );
    Stack& operator=(Stack&&);
    BoolProxy top();
    //const BoolProxy top() const;
    bool pop();
    bool push(const bool);
    void clear();
    size_t size() const;
    bool full() const; bool empty() const;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

template <size_t N>
Stack<bool, N>::Stack() : _top(std::make_unique<size_t>(0)), _data{}
{
}

template <size_t N>
Stack<bool, N>::Stack(Stack<bool, N>&& other) : 
  _top(std::move(other._top)), 
  _data(std::move(other._data))
{
}

template <size_t N>
Stack<bool, N>& Stack<bool, N>::operator=(Stack<bool, N>&& other)
{
  if (this != &other)
  {
    _top = std::move(other._top);
    _data = std::move(other._data);
  }
  return *this;
}

template<size_t N>
bool Stack<bool, N>::full() const
{
  return *_top == N;
}

template<size_t N>
bool Stack<bool, N>::empty() const 
{
  return *_top == 0;
}

template<size_t N>
size_t Stack<bool,N>::size() const
{
  return *_top;
}

template <size_t N>
typename Stack<bool, N>::BoolProxy Stack<bool, N>::top()
{
  if (empty()) throw std::runtime_error("Called top() on an empty stack");
  auto idx {(*_top - 1) / 8};
  auto offset { (*_top - 1) % 8 };
  return BoolProxy { _data[idx], offset };
}

/*template <size_t N>
const typename Stack<bool, N>::BoolProxy Stack<bool, N>::top() const
{
  if (empty()) throw std::runtime_error("Called top() on an empty stack");
  return BoolProxy { _data[*_top / 8], *_top % 8 };
}*/

template <size_t N>
bool Stack<bool, N>::pop()
{
  if (empty()) return false;
  --*_top;
  return true;
}

template <size_t N>
bool Stack<bool, N>::push(bool item)
{
  if (full()) return false;
  auto idx { *_top / 8 };
  auto offset { *_top % 8 };
  BoolProxy { _data[idx], offset } = item;
  std::bitset<8>b(_data[idx]);
  (*_top)++;
  return true;
}

template <size_t N>
void Stack<bool, N>::clear()
{
  *_top = 0;
}

template <size_t N>
typename Stack<bool, N>::iterator Stack<bool, N>::begin()
{
  return StackIterator{this, *_top};
}

template <size_t N>
typename Stack<bool, N>::iterator Stack<bool, N>::end()
{
  return StackIterator { this, 0 };
}

template <size_t N>
typename Stack<bool, N>::const_iterator Stack<bool, N>::begin() const
{
  return StackIterator{this, *_top};
}

template <size_t N>
typename Stack<bool, N>::const_iterator Stack<bool, N>::end() const
{
  return StackIterator { this,  0};
}

template <size_t N>
bool Stack<bool, N>::StackIterator::operator*()
{
  return BoolProxy { _stack->_data[(_idx-1)/8], (_idx-1)%8 };
}

template <size_t N>
typename Stack<bool,N>::StackIterator Stack<bool, N>::StackIterator::operator++() 
{
  --_idx;
}

template <size_t N>
bool Stack<bool, N>::StackIterator::operator!=(const Stack<bool,N>::StackIterator &other) const
{
  return _stack != other._stack || _idx != other._idx;
}

template <size_t N>
const bool Stack<bool, N>::StackIterator::operator*() const
{
  return BoolProxy { _stack->_data[(_idx-1)/8], (_idx-1)%8 };
}

template <size_t N>
Stack<bool, N>::StackIterator::StackIterator(Stack<bool, N>* stack, size_t idx) : 
  _stack(stack), 
  _idx(idx)
{
}

template <size_t N>
Stack<bool, N>::BoolProxy::BoolProxy(unsigned char& data, size_t offset) : 
  data(data), mask(1 << offset)
{
}

template <size_t N>
Stack<bool, N>::BoolProxy::operator bool() const 
{
  return data & mask;
}

template <size_t N>
typename Stack<bool, N>::BoolProxy& Stack<bool, N>::BoolProxy::operator=(bool value)
{
  if (value) 
  {
    data |= mask;
  }
  else 
  {
    data &= ~mask;
  }
  return *this;
}

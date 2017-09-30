#include "odd_range.h"
#include <iostream>

using namespace std;

OddRange::OddRange(const unsigned int start, const unsigned int end) : _start((start % 2 == 0 ? start + 1 : start)), _end((end % 2 == 0 ? end + 1 : end))
{
}

OddRange::iterator OddRange::begin()
{
  return OddRange::OddIterator { _start };
}

OddRange::iterator OddRange::end()
{
  return OddRange::OddIterator { _end };
}

OddRange::const_iterator OddRange::begin() const
{
  return OddRange::OddIterator { _start };
}

OddRange::const_iterator OddRange::end() const
{
  return OddRange::OddIterator { _end };
}

OddRange::OddIterator::OddIterator(const unsigned int start) : start(start)
{
}

OddRange::OddIterator& OddRange::OddIterator::operator++() 
{
  start+=2;
  return *this;
}

OddRange::OddIterator OddRange::OddIterator::operator++(int unused)
{
  OddIterator tmp { start };
  start+=2;
  return tmp;
}

unsigned int OddRange::OddIterator::operator*() const 
{
  return start;
}

bool OddRange::OddIterator::operator==(const OddRange::OddIterator& other) const
{
  return start == other.start;
}

bool OddRange::OddIterator::operator!=(const OddRange::OddIterator& other) const 
{
  return !operator==(other);
}

int main(int argc, char** argv) 
{
  for (auto i : OddRange{1,7})
  {
    cout << i << endl;
  }

  cout << endl;

  for (auto i : OddRange{2,8})
  {
    cout << i << endl;
  }

  return 0;
}

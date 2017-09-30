class OddRange
{
  private:
    const unsigned int _start;
    const unsigned int _end;
    struct OddIterator
    {
      unsigned int start;
      OddIterator(const unsigned int);
      OddIterator& operator++();
      OddIterator operator++(int);
      unsigned int operator*() const;
      bool operator==(const OddIterator&) const;
      bool operator!=(const OddIterator&) const;
    };
  public:
    using iterator = OddIterator;
    using const_iterator = const OddIterator;
    OddRange(const unsigned int start, const unsigned int end);
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

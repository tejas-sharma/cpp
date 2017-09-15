#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Polynomial
{
  public:
    int _degree;
    vector<double> _coefficients;
    friend ostream& operator<<(ostream&, const Polynomial&);
    ~Polynomial();
    Polynomial();
    Polynomial(const Polynomial &) = default;
    Polynomial(int degree);
    Polynomial& operator=(Polynomial &&other);
};

Polynomial::~Polynomial() 
{
}

Polynomial::Polynomial() : Polynomial(0) 
{
}

Polynomial::Polynomial(int degree) : _degree(degree)
{
}

Polynomial& Polynomial::operator=(Polynomial &&other)
{
  cout << "In Move Constructor" << endl;
  _degree = std::move(other._degree);
  _coefficients = std::move(other._coefficients);
}

ostream& operator<<(ostream& os, const Polynomial &poly)
{
  return os << poly._degree;
}

Polynomial f(double c2, double c1, double c0) 
{
  Polynomial p { 2 };
  p._coefficients = { c0, c1, c2 };
  return p;
}

int main(int argc, char ** argv) 
{
  cout << "Constructing p" << endl;
  Polynomial p1 = f(1,2,3);
  Polynomial p2;
  p2 = std::move(p1);

  return 0;
}

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
    Polynomial(const std::initializer_list<double> &coefficients);
    Polynomial& operator=(const std::initializer_list<double> &coefficients);
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
  return *this;
}

Polynomial& Polynomial::operator=(const std::initializer_list<double> &coefficients) 
{
  cout << "In initializer list assignment op" << endl;
  _degree = coefficients.size();
  _coefficients = coefficients;
  return *this;
}

Polynomial::Polynomial(const std::initializer_list<double> &coefficients) : _coefficients(coefficients), _degree(coefficients.size())
{
  cout << "In initializer list constructor" << endl;
}

ostream& operator<<(ostream& os, const Polynomial &poly)
{
   auto& ret = os << poly._degree << ' ';
   for (auto c : poly._coefficients) 
   {
     ret << c << ' ';
   }
   return ret;
}

Polynomial f(double c2, double c1, double c0) 
{
  Polynomial p { 2 };
  p._coefficients = { c0, c1, c2 };
  return p;
}

int main(int argc, char ** argv) 
{
  Polynomial p { 1.0, 2.0, 3.0 };
  auto il = { 1.0, 2.0, 3.0 };
  Polynomial p2;
  p2 = il;
  cout << p << endl;
  cout << p2 << endl;
  return 0;
}

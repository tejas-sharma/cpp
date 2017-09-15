#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Polynomial
{
  private:
    int _degree;
    std::unique_ptr<vector<double> > _coefficients;
    friend ostream& operator<<(ostream&, const Polynomial&);
  public:
    ~Polynomial();
    Polynomial();
    Polynomial(int degree);
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

ostream& operator<<(ostream& os, const Polynomial &poly)
{
  return os << "degree: " << poly._degree;
}

int main(int argc, char ** argv) 
{
  Polynomial p { 5 };
  cout << p << endl;
  return 0;
}

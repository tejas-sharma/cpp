#include <iostream>
#include <cmath>

using namespace std;

template <class F>
double integrate(F func, double start, double end, int intervals)
{
  double h = (end - start) / intervals;
  double firstPart { ((h * func(start)) / 2) + ((h * func(end)) / 2) };
  double secondPart { 0 };
  for (auto i = 0; i < intervals - 1; ++i) 
  {
    secondPart = func(start + (i * h));
  }
  return firstPart + (h * secondPart);
}

double exp3f(double x) 
{
  return std::exp(3.0 * x);
}

struct exp3t 
{
  double operator() (double x) const 
  {
    return std::exp(3.0 * x);
  } 
};

struct CosFunctor 
{
  double operator() (double x)
  {
    return (2 * std::cos(x)) + std::pow(x,2);
  }
};

struct FirstCosIntegral 
{
  double operator() (int x)
  {
    return integrate(CosFunctor{}, 0.0, 2.0, 10);
  }
};


int main(int argc, char** argv) 
{
  cout << integrate(exp3f, 0, 4, 10) << endl;
  cout << integrate(exp3t{}, 0, 4, 10) << endl;
  cout << integrate((double(*) (double))&std::sin, 0.0, 2.0, 10) << endl; // need to specify which overload we want
  auto secondCosIntegral = integrate(FirstCosIntegral{}, 0.0, 2.0, 10);
  cout << secondCosIntegral << endl;
  auto secondCosIntegral2 = integrate([](double x){ return integrate([](double x){ return (2 * std::cos(x)) + std::pow(x,2); }, 0.0, 2.0, 10); },0.0, 2.0, 10);
  cout << secondCosIntegral2 << endl;
}

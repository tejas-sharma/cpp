#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct DoubleCompare
{
  bool operator() (const double& left, const double& right) { return left < right; }
};

int main(int argc, char* argv[]) 
{
  vector<double> v1 { -9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2 };
  std::sort(std::begin(v1), std::end(v1), [](const auto& left, const auto& right) { return left < right; });
  for (auto i : v1) cout << i << endl;
  vector<double> v2 { -9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2 };
  std::sort(std::begin(v2), std::end(v2), DoubleCompare{});
  for (auto i : v2) cout << i << endl;
  return 0;
}

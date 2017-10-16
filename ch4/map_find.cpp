#include <map>
#include <iostream>
#include <algorithm>

using namespace std;


int main(int argc, char* argv[]) 
{
  map<string, double> numbers 
  {
    {"tejas", 1},
    {"shruti", 2},
    {"sharma", 3},
    {"chalamani", 4}
  };
  auto sharmaIt = numbers.find("tejas");
  if (sharmaIt != numbers.end()) cout << sharmaIt->second << endl;

  auto sharmaManiIt = numbers.find("sharmamani");
  if (sharmaManiIt != numbers.end())
  {
    cout << "sharmamani found!" << endl;
    cout << sharmaManiIt->second << endl;
  }
  else 
  {
    cout << "sharmamani not found" << endl;
  }

  auto fourIt = find_if(numbers.begin(), numbers.end(), [](const auto& elem) { return elem.second == 4; });
  if (fourIt != numbers.end()) 
  {
    cout << "Four found, " << fourIt->first << endl;
  }
  else 
  {
    cout << "Four not found" << endl;
  }

  auto sixIt = find_if(numbers.begin(), numbers.end(), [](const std::pair<string, double>& elem) { return elem.second == 6; });
  if (sixIt != numbers.end())
  {
    cout << "Six found, " << sixIt->first << endl;
  }
  else 
  {
    cout << "Six not found" << endl;
  }

  return 0;
}

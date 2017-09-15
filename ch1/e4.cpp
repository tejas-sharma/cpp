#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char ** argv) 
{
  if (argc != 2) 
  {
    cerr << "Incorrect usage" << endl;
    return 1;
  }

  fstream fs(argv[1], std::fstream::in);
  if (fs.is_open())
  {
    string line;
    while (std::getline(fs, line))
    {
      if (line.find_first_of("%") != 0)
      {
        stringstream ss;
        ss << line << endl;

        vector<string> parts;
        string part;
        while (getline(ss, part, ' ')) 
        {
          parts.push_back(part);
        }
        if (parts.size() > 2) 
        {
          cout << "Rows: " << parts[0] << endl << "Columns: " << parts[1] << endl << "Non Zero: " << parts[2] << endl;
        }
        else 
        {
          cout << "Unexpected format" << endl;
        }
        break;
      }
    }
  }
  return 0;
}

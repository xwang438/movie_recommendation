#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <ctime>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

inline string inttostr(int a)
{
	std::stringstream ss;
	ss << a;
	string s = ss.str();
	return s;
}

inline int strtoint(string s)
{
	std::stringstream convert(s);
	int value;
	if(!(convert >> value))
		value = 0;
	return value;
}

inline string doubletostr(double d)
{
	std::stringstream ss;
	ss << d;
	string s = ss.str();
	return s;
}

inline double strtodouble(string s)
{
  std::stringstream convert(s);
  double d;
  if(!(convert >> d))
    d = 0;
  return d;
}

//The following method reads a file and stores the data in a vector
inline vector<vector<string> > storefile(const char* filename, char interval, int num)
{
	ifstream infile;
  infile.open(filename);
  string line;
  vector<vector<string> > vectornew;
  while(!infile.eof())
  {
    getline(infile, line);
    if(line.size() > 0)
    {
      vector<string> vn;
      int pos1 = 0, pos2 = 0;
      string::size_type l = pos1;
      while(pos2 != line.size()){
        if(line.at(pos2) == interval){
          vn.push_back(line.substr(pos1, pos2-pos1));
          pos1 = pos2 + num;
          pos2 = pos1 +1 ;
        }
        else
          pos2 ++;
      }
      vn.push_back(line.substr(pos1));
      vectornew.push_back(vn);
    }
  }

    infile.close();
    return vectornew;   
}
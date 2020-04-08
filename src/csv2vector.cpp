#include <fstream>
#include <sstream>
#include <iostream>
#include "../include/csv2vector.hpp"

//--------------------------2D vector 2 1D--------------------------------------------

std::vector<double> onelinevector(const std::vector<std::vector<double>> &invector) {

  std::vector<double> v1d;
  if (invector.size() == 0)
    return v1d;
  v1d.reserve(invector.size() * invector.front().size());

  for (auto &innervector : invector) {
    v1d.insert(v1d.end(), innervector.begin(), innervector.end());
  }

  return v1d;
}

//-------------------------csv2vector Funktionsdefinition--------------------------

std::vector<std::vector<double>> csv2Dvector(std::string inputFileName) {
  using namespace std;

  vector<vector<double>> data;
  ifstream inputFile(inputFileName);
  int l = 0;

  while (inputFile) {
    l++;
    string s;
    if (!getline(inputFile, s))
      break;
    if (s[0] != '#') {
      istringstream ss(s);
      vector<double> record;

      while (ss) {
        string line;
        if (!getline(ss, line, ','))
          break;
        try {
          record.push_back(stof(line));
        } catch (const std::invalid_argument e) {
          cout << "NaN found in file " << inputFileName << " line " << l
               << endl;
          e.what();
        }
      }

      data.push_back(record);
    }
  }

  if (!inputFile.eof()) {
    cerr << "Could not read file " << inputFileName << "\n";
    throw invalid_argument("File not found.");
  }

  return data;
}
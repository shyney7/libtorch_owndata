#pragma once
#include <vector>
#include <string>

//----------------------Funktionsprototyp Onelinevector----------------------

std::vector<double> onelinevector(const std::vector<std::vector<double>> &invector);

//------------------------Funktionsprototyp csv2Dvector----------------------

std::vector<std::vector<double>> csv2Dvector(std::string inputFileName);
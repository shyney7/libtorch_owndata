#pragma once
#include <vector>
#include <string>

//----------------------Funktionsprototyp Onelinevector----------------------

std::vector<float> onelinevector(const std::vector<std::vector<float>> &invector);

//------------------------Funktionsprototyp csv2Dvector----------------------

std::vector<std::vector<float>> csv2Dvector(std::string inputFileName);
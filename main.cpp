#include <iostream>           //cout cin etc.
#include "include/owndata.hpp"//Eigene Datenvorbereitungsbib
#include <torch/torch.h>      //torchlib
#include <numeric>            // accumulate & inner_product
#include <cmath>              //sqrt()
#include <functional>         //reference_wrapper

float stdfunc(std::vector<float> const &invector);

int main() {

OwnData test("input.csv","output.csv");

std::cout << "Shapeprint x2data: " << std::endl;
for ( const auto &row : test.x2data )
{
   for ( const auto &s : row ) std::cout << s << ' ';
   std::cout << std::endl;
}

std::cout << "Shapeprint y2data: " << std::endl;
for ( const auto &row : test.y2data )
{
   for ( const auto &s : row ) std::cout << s << ' ';
   std::cout << std::endl;
}

//test der referenz vector methode:
std::vector<std::reference_wrapper<float>> colvec0;
colvec0.reserve(test.x2data.size());
for (int i(0); i< test.x2data.size(); ++i) colvec0.push_back(test.x2data[i][0]);
std::cout << "-------------- col0: "<<std::endl;
std::cout << colvec0 << std::endl;

//test der std funktion:
std::vector<float> testv {6,3,2,9,11,44,20};
float stdw = stdfunc(testv);
std::cout << "Standardabw: " << stdw << std::endl;

    return 0;
}

//-------Standardabweichung Funktion-------
float stdfunc(std::vector<float> const & invector) {

   float mean = std::accumulate(invector.begin(), invector.end(), 0.0f) / invector.size();

   float sq_sum = std::inner_product(invector.begin(), invector.end(), invector.begin(), 0.0f,
         [](float const & x, float const & y) {return x+y;},
         [mean](float const & x, float const & y) {return (x-mean)*(y-mean);});

   return std::sqrt(sq_sum / (invector.size() - 1));
}
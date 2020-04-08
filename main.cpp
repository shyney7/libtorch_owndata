#include <iostream>           //cout cin etc.
#include "include/owndata.hpp"//Eigene Datenvorbereitungsbib
#include <torch/torch.h>      //torchlib
#include <numeric>            // accumulate & inner_product
#include <cmath>              //sqrt()
#include <functional>         //reference_wrapper

double stdfunc1(std::vector<std::reference_wrapper<double>> const &invector);

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
std::vector<std::reference_wrapper<double>> colvec0;
colvec0.reserve(test.x2data.size());
for (int i(0); i< test.x2data.size(); ++i) colvec0.push_back(test.x2data[i][0]);
std::cout << "-------------- col0: "<<std::endl;
std::cout << colvec0 << std::endl;

//test der std funktion:
std::vector<double> testv {6,3,2,9,11,44,20};
std::vector<std::reference_wrapper<double>> testvref;
for (int j(0); j<testv.size(); j++) testvref.push_back(testv[j]);
double stdw = stdfunc1(testvref);
std::cout << "Standardabw: " << stdw << std::endl;

//test der normalisierung von 2D Vectoren:
std::cout << "Ab hier Std von 2D vectoren: " << std::endl;

std::vector<std::vector<double>> std2dvector{{8,20,8},{10,15,10},{15,10,15},{20,8,20}};
std::cout << "\ntest vector vor normalisierung: " << std::endl;
for ( const auto &row : std2dvector )
{
   for ( const auto &s : row ) std::cout << s << ' ';
   std::cout << std::endl;
}

std::vector<std::reference_wrapper<double>> colvec;
        colvec.reserve(std2dvector.size());

 for(int coliterator(0); coliterator < std2dvector.front().size(); coliterator++) {
        for (int i(0); i< std2dvector.size(); i++) {
        colvec.push_back(std2dvector[i][coliterator]);
        }
        
    double stddev = stdfunc1(colvec);
    double mean = std::accumulate(colvec.begin(), colvec.end(), 0.0) / colvec.size();

        for (int rowcalit(0); rowcalit < std2dvector.size(); rowcalit++) {
            std2dvector[rowcalit][coliterator] = ((std2dvector[rowcalit][coliterator])-mean) / stddev;    
        }
    //erase all values from ref vector
    colvec.clear();
    }

std::cout << "\nvector nach normalisierung: " << std::endl;
for ( const auto &row : std2dvector )
{
   for ( const auto &s : row ) std::cout << s << ' ';
   std::cout << std::endl;
}

    return 0;
}

//-------Standardabweichung Funktion-------
double stdfunc1(std::vector<std::reference_wrapper<double>> const & invector) {

   double mean = std::accumulate(invector.begin(), invector.end(), 0.0) / invector.size();

   double sq_sum = std::inner_product(invector.begin(), invector.end(), invector.begin(), 0.0,
         [](double const & x, double const & y) {return x+y;},
         [mean](double const & x, double const & y) {return (x-mean)*(y-mean);});

   return std::sqrt(sq_sum / (invector.size() - 1));
}
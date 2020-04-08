#include "../include/owndata.hpp"       //header
//#include <iostream>
//#include <string>
#include <algorithm>                    //shuffle
#include <random>                       //seed generation
#include "../include/csv2vector.hpp"    //csv functions
#include <numeric>                      //inner_product; accumulate
#include <cmath>                        //sqrt()


//-------Standard Deviation Function:-------
double stdfunc(std::vector<std::reference_wrapper<double>> const & invector) {

   double mean = std::accumulate(invector.begin(), invector.end(), 0.0) / invector.size();

   double sq_sum = std::inner_product(invector.begin(), invector.end(), invector.begin(), 0.0,
         [](double const & x, double const & y) {return x+y;},
         [mean](double const & x, double const & y) {return (x-mean)*(y-mean);});

   return std::sqrt(sq_sum / (invector.size() - 1));
}

    //---OwnData class constructor (create 2D vector and shuffle if true):-------

    OwnData::OwnData(std::string inputpath, std::string outputpath, bool shuff) {
        
        x2data = csv2Dvector(inputpath);
        y2data = csv2Dvector(outputpath);

        if(shuff) {
            std::random_device r;
            std::seed_seq rng_seed{r(),r(),r(),r(),r(),r(),r(),r()};

            //erzeugen von random engines mit den seeds die gleich sind:
            std::mt19937 eng1(rng_seed);
            auto eng2 = eng1;

            std::shuffle(x2data.begin(), x2data.end(), eng1);
            std::shuffle(y2data.begin(), y2data.end(), eng2);
        }
    }

    //class function to normalize the data (z-score normalization)
    // (x-mean)/std deviation:
    void OwnData::normalize() {

        std::vector<std::reference_wrapper<double>> colvec;
        colvec.reserve(x2data.size());

    //normalize input vector:
    for(int coliterator(0); coliterator < x2data.front().size(); coliterator++) {
        for (int i(0); i< x2data.size(); i++) {
        colvec.push_back(x2data[i][coliterator]);
        }
        
    double stddev = stdfunc(colvec);
    double mean = std::accumulate(colvec.begin(), colvec.end(), 0.0) / colvec.size();

        for (int rowcalit(0); rowcalit < x2data.size(); rowcalit++) {
            x2data[rowcalit][coliterator] = ((x2data[rowcalit][coliterator])-mean) / stddev;    
        }
    //erase all values from ref vector
    colvec.clear();
    }
    //normalize output vector:
        for(int coliterator(0); coliterator < y2data.front().size(); coliterator++) {
        for (int i(0); i< y2data.size(); i++) {
        colvec.push_back(y2data[i][coliterator]);
        }
        
    double stddev = stdfunc(colvec);
    double mean = std::accumulate(colvec.begin(), colvec.end(), 0.0) / colvec.size();

        for (int rowcalit(0); rowcalit < y2data.size(); rowcalit++) {
            y2data[rowcalit][coliterator] = ((y2data[rowcalit][coliterator])-mean) / stddev;    
        }
    //erase all values from ref vector
    colvec.clear();
    }
        
    }




#include "../include/owndata.hpp"
//#include <iostream>
//#include <string>
#include <algorithm>
#include <random>
#include "../include/csv2vector.hpp"


    OwnData::OwnData(std::string inputpath, std::string outputpath, bool shuff=0) {
        
        x2data = csv2Dvector(inputpath);
        y2data = csv2Dvector(outputpath);

        if(shuff) {
            auto rng_seed = std::default_random_engine {};
            std::shuffle(x2data.begin(), x2data.end(), rng_seed);
            std::shuffle(y2data.begin(), y2data.end(), rng_seed);
        }
    }




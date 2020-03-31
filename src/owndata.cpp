#include "../include/owndata.hpp"
//#include <iostream>
//#include <string>
#include <algorithm>
#include <random>
#include "../include/csv2vector.hpp"


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




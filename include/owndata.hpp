#pragma once
#include <vector>
#include <string>
#include <functional>   //reference_wrapper

double stdfunc(std::vector<std::reference_wrapper<double>> const & invector);

class OwnData {
    public:
    std::vector<std::vector<double>> x2data, y2data;
    public:
    OwnData(std::string inputpath, std::string outputpath, bool shuff=0);

    void normalize();

};
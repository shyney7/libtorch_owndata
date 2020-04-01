#pragma once
#include <vector>
#include <string>

class OwnData {
    public:
    std::vector<std::vector<float>> x2data, y2data;
    public:
    OwnData(std::string inputpath, std::string outputpath, bool shuff=0);
    
    

};
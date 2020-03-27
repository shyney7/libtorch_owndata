#include <iostream>
#include "include/owndata.hpp"
#include <torch/torch.h>

int main() {

OwnData test("input.csv","output.csv",1);

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
    return 0;
}
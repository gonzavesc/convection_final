#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath> //std::pow abs
#include <new>
#include <algorithm>  //std::max

#include "read.hpp"


#include "initialize.hpp"


#include "export.hpp"


#include "method.hpp"
#ifndef INCLUDE_BND
#define INCLUDE_BND
class inlet{
    private:
        double alpha;
    public:
        inlet(const double&);
        double u(const double&);
        double get_a();
};

void def_bnd(std::vector<std::vector<double>>& ap, std::vector<std::vector<double>>& ae,  std::vector<std::vector<double>>& aw,  std::vector<std::vector<double>>& an, std::vector<std::vector<double>>& as,
             std::vector<std::vector<double>>& ap0,  std::vector<std::vector<double>>& b, inlet& in,  differential& diff);
#endif
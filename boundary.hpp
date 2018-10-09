#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath> //std::pow abs
#include <new>
#include <algorithm>  //std::max
#ifndef INCLUDE_READ
	#include "read.hpp"
	#define INCLUDE_READ
#endif
#ifndef INCLUDE_IN
	#include "initialize.hpp"
	#define INCLUDE_IN
#endif
#ifndef INCLUDE_EXP
    #include "export.hpp"
    #define INCLUDE_EXP
#endif
#ifndef INCLUDE_MET
    #include "method.hpp"
    #define INCLUDE_MET
#endif
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
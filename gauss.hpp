#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath> //std::pow abs
#include <new>
#include <algorithm>  //std::max

#include "read.hpp"

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
#ifndef INCLUDE_BND
    #include "boundary.hpp"
    #define INCLUDE_BND
#endif


void copyMatrix(std::vector<std::vector<double>>& phi_p, const std::vector<std::vector<double>>& phi);
class gauss{
    private:
        double err;
    public:
        gauss(const double& a);
        double get_err();
        void solver(std::vector<std::vector<double>>& phi, const std::vector<std::vector<double>>& phi_p, const std::vector<std::vector<double>>& ap, const std::vector<std::vector<double>>& ae, const std::vector<std::vector<double>>& aw, const std::vector<std::vector<double>>& an, const std::vector<std::vector<double>>& as,
            const std::vector<std::vector<double>>& ap0, const std::vector<std::vector<double>>& b);
};

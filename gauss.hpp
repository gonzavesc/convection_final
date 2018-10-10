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

#include "boundary.hpp"

#ifndef INCLUDE_GSS
#define INCLUDE_GSS

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
#endif
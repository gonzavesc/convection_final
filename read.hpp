#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath>
#include <new>
#ifndef INCLUDE_READ
#define INCLUDE_READ
std::vector<double> readfiledat();
class properties{
    private:
        double rho,gamma;
    public:
        properties(const double&, const double&);
        double get_rho();
        double get_gamma();
};
class differential{
    private:
        double dx,dy,dt;
    public:
        differential(const double&, const double&, const double&);
        double get_dx();
        double get_dy();
        double get_dt();
};
#endif
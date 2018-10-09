#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath>
#include <new>

#ifndef INCLUDE_READ
	#include "read.hpp"
	#define INCLUDE_READ
#endif

std::vector<double> readfiledat()
{
    std::ifstream file;
    std::vector<double> v;

    file.open("config.dat");    
    std::string name;
    while (file >> name) 
    {
        double a;

        file >> a;
        v.push_back(a);
    }
    return v;
}
properties::properties(const double& a, const double& b)
{
    rho = a;
    gamma = b;
}
double properties::get_rho()
{
    return rho;
}
double properties::get_gamma()
{
    return gamma;
}

differential::differential(const double& a, const double& b, const double& c)
{
    dx = a; dy = b; dt = c;
}
double differential::get_dx()
{
    return dx;
}

double differential::get_dy()
{
    return dy;
}
double differential::get_dt()
{
    return dt;
}
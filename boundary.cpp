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
#ifndef INCLUDE_BND
    #include "boundary.hpp"
    #define INCLUDE_BND
#endif
double inlet(const double&x)
{
    double T;
    T = 1 + tanh((2 * x + 1) * alpha);
    return T;
}
void def_bnd(std::vector<std::vector<double>>& ap, std::vector<std::vector<double>>& ae,  std::vector<std::vector<double>>& aw,  std::vector<std::vector<double>>& an, std::vector<std::vector<double>>& as,
             std::vector<std::vector<double>>& ap0,  std::vector<std::vector<double>>& b)
{
    double A,x;
    A = 1 - tanh(alpha);
    int j = 0;
    int i =0;
    for ( i = 0; i <= Ny; i++)
    {
        ap[i][j] = 1; ae[i][j] = 0; aw[i][j] = 0; an[i][j] = 0; as[i][j] = 0; ap0[i][j] = 0; b[i][j] = A;
    }
    i = Ny;
    for ( j = 0; j <= Nx; j++)
    {
        ap[i][j] = 1; ae[i][j] = 0; aw[i][j] = 0; an[i][j] = 0; as[i][j] = 0; ap0[i][j] = 0; b[i][j] = A;
    }
    j = Nx;
    for ( i = 0; i <= Ny; i++)
    {
        ap[i][j] = 1; ae[i][j] = 0; aw[i][j] = 0; an[i][j] = 0; as[i][j] = 0; ap0[i][j] = 0; b[i][j] = A;
    }
    i = 0;
    for ( j = Nx / 2 + 1; j <= Nx; j++)
    {
        ap[i][j] = 1; ae[i][j] = 0; aw[i][j] = 0; an[i][j] = 1; as[i][j] = 0; ap0[i][j] = 0; b[i][j] = 0;
    }
    for (j = 0; j <= Nx / 2; j++)
    {
        x = (j - Nx / 2) * diff[0];
        ap[i][j] = 1; ae[i][j] = 0; aw[i][j] = 0; an[i][j] = 0; as[i][j] = 0; ap0[i][j] = 0; b[i][j] = inlet(x);
    }

}
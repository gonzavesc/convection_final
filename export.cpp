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

void exportarMatriu(const std::vector<std::vector<double>>& phi)
{
    int i, jj, Nx, Ny;
    std::ofstream output;
    output.open("Matrix.dat");
    Ny = phi.size() - 1;
    Nx = phi[0].size() - 1;
    for (i = 0; i <= Ny; i++)
    {
        for (jj = 0; jj <= Nx - 1; jj++)
        {
             output << phi[i][jj] << ", " ;
        }
        output << phi[i][Nx] << std::endl;
    }
    output.close();
}
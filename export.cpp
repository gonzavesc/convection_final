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

void exportarMatriu(const std::vector<std::vector<double>>& phi)
{
    int i, jj;
    std::ofstream output;
    output.open("Matrix.dat");
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
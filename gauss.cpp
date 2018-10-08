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

#ifndef INCLUDE_GSS
    #include "gauss.hpp"
    #define INCLUDE_GSS
#endif

void copyMatrix(std::vector<std::vector<double>>& phi_p, const std::vector<std::vector<double>>& phi)
{
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            phi_p[i][j] = phi[i][j];
        }
    }
}

void Gauss_seidel(std::vector<std::vector<double>>& phi, const std::vector<std::vector<double>>& phi_p, const std::vector<std::vector<double>>& ap, const std::vector<std::vector<double>>& ae, const std::vector<std::vector<double>>& aw, const std::vector<std::vector<double>>& an, const std::vector<std::vector<double>>& as,
            const std::vector<std::vector<double>>& ap0, const std::vector<std::vector<double>>& b)
{
    double rms,prev;
    int i,j;
    rms = 1 + err;
    while (rms > err)
    {
        rms = 0;
        for (i = 1; i <= Ny-1; i++)
        {
            for (j = 1; j <= Nx-1; j++)
            {
                prev = phi[i][j];
                phi[i][j] = (ae[i][j] * phi[i][j+1] + aw[i][j] * phi[i][j-1] + an[i][j] * phi[i + 1][j] + as[i][j] * phi[i-1][j] + b[i][j] + ap0[i][j] * phi_p[i][j]) / ap[i][j];
                rms = std::max(rms, std::abs(phi[i][j] - prev));
            }
        }
        
        for (j = 1; j <= Nx-1; j++)
        {
            i = 0;
            prev = phi[i][j];
            phi[i][j] = (ae[i][j] * phi[i][j+1] + aw[i][j] * phi[i][j-1] + an[i][j] * phi[i + 1][j] + b[i][j] + ap0[i][j] * phi_p[i][j]) / ap[i][j];
            rms = std::max(rms, std::abs(phi[i][j] - prev));
            i = Ny;
            prev = phi[i][j];
            phi[i][j] = (ae[i][j] * phi[i][j+1] + aw[i][j] * phi[i][j-1] + as[i][j] * phi[i-1][j] + b[i][j] + ap0[i][j] * phi_p[i][j]) / ap[i][j];
            rms = std::max(rms, std::abs(phi[i][j] - prev));
        }
        for (i = 0; i <= Ny; i++)
        {
            j = 0;
            prev = phi[i][j];
            phi[i][j] = (b[i][j] + ap0[i][j] * phi_p[i][j]) / ap[i][j];
            rms = std::max(rms, std::abs(phi[i][j] - prev));
            j = Nx;
            prev = phi[i][j];
            phi[i][j] = (b[i][j] + ap0[i][j] * phi_p[i][j]) / ap[i][j];
            rms = std::max(rms, std::abs(phi[i][j] - prev));
        }
        //std::cout << rms << std::endl;
    }
}
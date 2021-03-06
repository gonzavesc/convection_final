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


#include "gauss.hpp"


void copyMatrix(std::vector<std::vector<double>>& phi_p, const std::vector<std::vector<double>>& phi)
{
    int Nx ,Ny;
    Nx = phi[0].size() - 1;
    Ny = phi.size() - 1;
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            phi_p[i][j] = phi[i][j];
        }
    }
}
gauss::gauss(const double& a)
{
    err = a;
}
double gauss::get_err()
{
    return err;
}
void gauss::solver(std::vector<std::vector<double>>& phi, const std::vector<std::vector<double>>& phi_p, const std::vector<std::vector<double>>& ap, const std::vector<std::vector<double>>& ae, const std::vector<std::vector<double>>& aw, const std::vector<std::vector<double>>& an, const std::vector<std::vector<double>>& as,
            const std::vector<std::vector<double>>& ap0, const std::vector<std::vector<double>>& b)
{
    double rms,prev;
    int i,j, Ny, Nx;
    Ny = phi.size() - 1;
    Nx=phi[0].size() - 1;
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
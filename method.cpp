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

double Set_A(const double& P,const double& Method)
{
    double A(0);
    if (Method == 0) //central difference
    {
        A = 1 - 0.5 * std::abs(P);
    }
    if (Method == 1) //Upwind
    {
        A = 1;
    }
    if (Method == 2) //hybrid
    {
        A = std::max(0.0, 1 - 0.5 * std::abs(P));
    }
    if (Method == 3) //Power Law
    {
        A = std::max(0.0, std::pow(1 - 0.5 * std::abs(P), 5));
    }
    if (Method == 4) //Exponential
    {
        A = std::abs(P) / (exp(std::abs(P)) - 1);
        if (P == 0)
        {
            A=1;
        }
    }
    return A;
}

void set_a(std::vector<std::vector<double>>& ae, std::vector<std::vector<double>>& aw, std::vector<std::vector<double>>& an, std::vector<std::vector<double>>& as,
        const std::vector<std::vector<double>>& Pe, const std::vector<std::vector<double>>& Pw, const std::vector<std::vector<double>>& Pn, const std::vector<std::vector<double>>& Ps,
        const std::vector<std::vector<double>>& Fe, const std::vector<std::vector<double>>& Fw, const std::vector<std::vector<double>>& Fn, const std::vector<std::vector<double>>& Fs,
        const std::vector<std::vector<double>>& De, const std::vector<std::vector<double>>& Dw, const std::vector<std::vector<double>>& Dn, const std::vector<std::vector<double>>& Ds, const int& Method )
{
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            ae[i][j] = De[i][j] * Set_A(Pe[i][j], Method) + std::max(-Fe[i][j], 0.0);
            aw[i][j] = Dw[i][j] * Set_A(Pw[i][j], Method) + std::max(Fw[i][j], 0.0);
            an[i][j] = Dn[i][j] * Set_A(Pn[i][j], Method) + std::max(-Fn[i][j], 0.0);
            as[i][j] = Ds[i][j] * Set_A(Ps[i][j], Method) + std::max(Fs[i][j], 0.0);
        }
    }
}

void set_ap(std::vector<std::vector<double>>& ap, const std::vector<std::vector<double>>& ae, const std::vector<std::vector<double>>& aw, const std::vector<std::vector<double>>& an, const std::vector<std::vector<double>>& as,
            const std::vector<std::vector<double>>& ap0, const std::vector<std::vector<double>>& b)
{
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            ap[i][j] = ae[i][j] + aw[i][j] + an[i][j] + as[i][j] + ap0[i][j] - b[i][j];
        }
    }
}
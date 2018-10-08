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

#ifndef INCLUDE_IN
	#include "initialize.hpp"
	#define INCLUDE_IN
#endif

double u(const double&x, const double& y)
{
    double uu;
    uu = 2 * y * (1 - x * x);
    return uu;
}
double v(const double&x, const double& y)
{
    double vv;
    vv = - 2 * x * (1 - y * y);
    return vv;
}

void set_F(std::vector<std::vector<double>>& Fe, std::vector<std::vector<double>>& Fw, std::vector<std::vector<double>>& Fn, std::vector<std::vector<double>>& Fs)
{
    double x,y;
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            x = (j - Nx / 2) * diff[0];
            y = i * diff[1];
            Fe[i][j] = properties[0] * u(x + diff[0] / 2, y) * diff[1];
            Fw[i][j] = properties[0] * u(x - diff[0] / 2, y) * diff[1];
            Fn[i][j] = properties[0] * v(x, y + diff[1] / 2) * diff[0];
            Fs[i][j] = properties[0] * v(x, y - diff[1] / 2) * diff[0];
        }
    }
}

void set_D(std::vector<std::vector<double>>& De, std::vector<std::vector<double>>& Dw, std::vector<std::vector<double>>& Dn, std::vector<std::vector<double>>& Ds)
{
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            De[i][j] = properties[1] * diff[1] / diff[0];
            Dw[i][j] = properties[1] * diff[1] / diff[0];
            Dn[i][j] = properties[1] * diff[0] / diff[1];
            Ds[i][j] = properties[1] * diff[0] / diff[1];
        }
    }
}

void set_P(std::vector<std::vector<double>>& Pe, std::vector<std::vector<double>>& Pw, std::vector<std::vector<double>>& Pn, std::vector<std::vector<double>>& Ps,
        const std::vector<std::vector<double>>& Fe, const std::vector<std::vector<double>>& Fw, const std::vector<std::vector<double>>& Fn, const std::vector<std::vector<double>>& Fs,
        const std::vector<std::vector<double>>& De, const std::vector<std::vector<double>>& Dw, const std::vector<std::vector<double>>& Dn, const std::vector<std::vector<double>>& Ds )
{
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            Pe[i][j] = Fe[i][j] / De[i][j];
            Pw[i][j] = Fw[i][j] / Dw[i][j];
            Pn[i][j] = Fn[i][j] / Dn[i][j];
            Ps[i][j] = Fs[i][j] / Ds[i][j];
        }
    }
}
void set_a0(std::vector<std::vector<double>>& ap0)
{
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            ap0[i][j] = properties[0] * diff[0] * diff[1] / diff[2];
        }
    }
}

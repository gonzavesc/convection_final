#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath>
#include <new>


#include "read.hpp"



#include "initialize.hpp"


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

void set_F(std::vector<std::vector<double>>& Fe, std::vector<std::vector<double>>& Fw, std::vector<std::vector<double>>& Fn, std::vector<std::vector<double>>& Fs, properties& prop, differential& diff)
{
    double x,y;
    int Nx, Ny;
    Ny = Fe.size() - 1;
    Nx = Fe[0].size() - 1;
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            x = (j - Nx / 2) * diff.get_dx();
            y = i * diff.get_dy();
            Fe[i][j] = prop.get_rho() * u(x + diff.get_dx() / 2, y) * diff.get_dy();
            Fw[i][j] = prop.get_rho() * u(x - diff.get_dx() / 2, y) * diff.get_dy();
            Fn[i][j] = prop.get_rho() * v(x, y + diff.get_dy() / 2) * diff.get_dx();
            Fs[i][j] = prop.get_rho() * v(x, y - diff.get_dy() / 2) * diff.get_dx();
        }
    }
}

void set_D(std::vector<std::vector<double>>& De, std::vector<std::vector<double>>& Dw, std::vector<std::vector<double>>& Dn, std::vector<std::vector<double>>& Ds, properties& prop, differential& diff)
{
    int Nx ,Ny;
    Nx = De[0].size() - 1;
    Ny = De.size() - 1;
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            De[i][j] = prop.get_gamma() * diff.get_dy() / diff.get_dx();
            Dw[i][j] = prop.get_gamma() * diff.get_dy() / diff.get_dx();
            Dn[i][j] = prop.get_gamma() * diff.get_dx() / diff.get_dy();
            Ds[i][j] = prop.get_gamma() * diff.get_dx() / diff.get_dy();
        }
    }
}

void set_P(std::vector<std::vector<double>>& Pe, std::vector<std::vector<double>>& Pw, std::vector<std::vector<double>>& Pn, std::vector<std::vector<double>>& Ps,
        const std::vector<std::vector<double>>& Fe, const std::vector<std::vector<double>>& Fw, const std::vector<std::vector<double>>& Fn, const std::vector<std::vector<double>>& Fs,
        const std::vector<std::vector<double>>& De, const std::vector<std::vector<double>>& Dw, const std::vector<std::vector<double>>& Dn, const std::vector<std::vector<double>>& Ds )
{
    int Nx ,Ny;
    Nx = De[0].size() - 1;
    Ny = De.size() - 1;
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
void set_a0(std::vector<std::vector<double>>& ap0, properties& prop, differential& diff)
{
    int Nx ,Ny;
    Nx = ap0[0].size() - 1;
    Ny = ap0.size() - 1;
    for (int i = 0; i <= Ny; i++)
    {
        for (int j = 0; j <= Nx; j++)
        {
            ap0[i][j] = prop.get_rho() * diff.get_dx() * diff.get_dy() / diff.get_dt();
        }
    }
}

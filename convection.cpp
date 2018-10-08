#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath> //std::pow std::abs
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

std::vector<double> properties, diff;
int Nx, Ny;
double alpha, err;
int main()
{
    std::vector<double> dat;
    int Method;
    double tot_time(0), runtime;
    dat = readfiledat();
    properties.push_back(dat[0]); properties.push_back(dat[1]);
    diff.push_back(dat[5]); diff.push_back(dat[6]); diff.push_back(dat[7]);
    Nx = dat[2] / diff[0]; Ny = dat[3] / diff[1];
    alpha = dat[4];
    Method = dat[10];
    runtime = dat[8];
    err = dat[11];
    std::vector<std::vector<double>> phi(Ny + 1, std::vector<double>(Nx +1, 100));
    std::vector<std::vector<double>> phi_p(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Fe(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Fw(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Fn(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Fs(Ny + 1, std::vector<double>(Nx +1, 0));

    std::vector<std::vector<double>> De(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Dw(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Dn(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Ds(Ny + 1, std::vector<double>(Nx +1, 0));

    std::vector<std::vector<double>> Pe(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Pw(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Pn(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> Ps(Ny + 1, std::vector<double>(Nx +1, 0));

    std::vector<std::vector<double>> ae(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> aw(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> an(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> as(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> ap(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> ap0(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> b(Ny + 1, std::vector<double>(Nx +1, 0));
    
    set_F(Fe, Fw, Fn, Fs);
    set_D(De, Dw, Dn, Ds);
    set_P(Pe, Pw, Pn, Ps, Fe, Fw, Fn, Fs, De, Dw, Dn, Ds);
    set_a(ae, aw, an, as, Pe, Pw, Pn, Ps, Fe, Fw, Fn, Fs, De, Dw, Dn, Ds, Method);
    
    set_a0(ap0);
    set_ap(ap, ae, aw, an, as, ap0, b);
    def_bnd(ap, ae, aw, an, as, ap0, b);
    
    while (tot_time < runtime)
    {
        tot_time+=diff[2];
        copyMatrix(phi_p,phi);
        //std::cout << tot_time << std::endl;
        Gauss_seidel(phi, phi_p, ap, ae, aw, an, as, ap0, b);
    }
    exportarMatriu(phi);

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath>
#include <new>

#include "read.hpp"
#ifndef INCLUDE_IN
#define INCLUDE_IN
double u(const double&x, const double& y);
double v(const double&x, const double& y);
void set_F(std::vector<std::vector<double>>& Fe, std::vector<std::vector<double>>& Fw, std::vector<std::vector<double>>& Fn, std::vector<std::vector<double>>& Fs, properties& prop, differential& diff);
void set_D(std::vector<std::vector<double>>& De, std::vector<std::vector<double>>& Dw, std::vector<std::vector<double>>& Dn, std::vector<std::vector<double>>& Ds, properties& prop, differential& diff);
void set_P(std::vector<std::vector<double>>& Pe, std::vector<std::vector<double>>& Pw, std::vector<std::vector<double>>& Pn, std::vector<std::vector<double>>& Ps,
        const std::vector<std::vector<double>>& Fe, const std::vector<std::vector<double>>& Fw, const std::vector<std::vector<double>>& Fn, const std::vector<std::vector<double>>& Fs,
        const std::vector<std::vector<double>>& De, const std::vector<std::vector<double>>& Dw, const std::vector<std::vector<double>>& Dn, const std::vector<std::vector<double>>& Ds );

void set_a0(std::vector<std::vector<double>>& ap0, properties& prop, differential& diff);
#endif
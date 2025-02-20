#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::setw;
using std::endl;
using std::left;
using std::abs;
using std::sqrt;

double ySk(double x);
void intervaloDalijimasPusiau(double& xm, double& x1, double& x2, double& r, double& l, double& L, double& ym);
void auksinisPjuvis(double& L, double& x1, double& x2, double& y1, double& y2, double& l, double& r, const double ap);
double niutonoMetodas(int& iteracijos, int& funkcijosKvietimas);
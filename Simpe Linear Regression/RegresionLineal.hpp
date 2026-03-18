#ifndef REGRESIONLINEAL_HPP
#define REGRESIONLINEAL_HPP

#include <vector>
using namespace std;

class RegresionLineal {
    vector<double> advertising;
    vector<double> sales;

    double B0;
    double B1;

    public:
    RegresionLineal(vector<double> x, vector<double> y);

    void CalcularModelo();

    double predecir(double x);

    double getB0();
    double getB1();
};


#endif
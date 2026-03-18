#include "RegresionLineal.hpp"

RegresionLineal::RegresionLineal(vector<double> x, vector<double> y){
    advertising = x;
    sales = y;
    B0 = 0;
    B1 = 0;
}

void RegresionLineal::CalcularModelo(){
    int n = advertising.size();

    double sumX = 0;
    double sumY = 0;
    double sumX2 = 0;
    double sumXY = 0;

    for (int i = 0; i < n; i++)
    {
        sumX += advertising[i];
        sumY += sales[i];
        sumX2 += advertising[i] * advertising[i];
        sumXY += advertising[i] * sales[i];
    }
    B1 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    B0 = (sumX2 * sumY - sumX * sumXY) / (n * sumX2 - sumX * sumX);
}

double RegresionLineal::predecir(double x){
    return B0 + B1 * x;
}

double RegresionLineal::getB0(){
    return B0;
}

double RegresionLineal::getB1(){
    return B1;
}
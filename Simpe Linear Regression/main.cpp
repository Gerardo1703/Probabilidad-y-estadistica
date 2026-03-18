#include <iostream>
#include <vector>
#include "RegresionLineal.hpp"

using namespace std;

int main() {
    vector<double> advertising = {23,26,30,34,43,48,52,57,58};
    vector<double> sales = {651,762,856,1063,1190,1298,1421,1440,1518};

    RegresionLineal modelo(advertising,sales);
    modelo.CalcularModelo();

    cout << "Ecuacion de Regresion: " << endl;
    cout << "sales = " << modelo.getB0() << " + " << modelo.getB1() << " * Advertising" << endl;
    cout << endl;
    cout << "predicciones: " << endl;

    vector<double> nuevosAdvertising = {60,65,70,80,90};

    for(double x : nuevosAdvertising){
        cout << "Advertising: " << x << " -> sales: " << modelo.predecir(x) << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include "TablaFrecuencia.hpp"

using namespace std;

int main(){
    vector<double> dataset = {
        12.3, 15.6, 14.2, 18.7, 21.4, 19.5, 22.1, 17.8, 16.4, 20.2
    };
    TablaFrecuencia tabla(dataset);
    tabla.CalcularFrecuencias();
    tabla.ImprimirTabla();

    return 0;
}
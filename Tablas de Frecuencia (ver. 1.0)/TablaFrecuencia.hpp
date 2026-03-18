#ifndef TABLAFRECUENCIA_HPP
#define TABLAFRECUENCIA_HPP

#include <vector>
#include <string>

using namespace std;

class TablaFrecuencia {

    vector<double> datos;
    vector<string> clases;
    vector<int> frecuencia;

    public:
    TablaFrecuencia(vector<double> d);

    void CalcularFrecuencias();
    void ImprimirTabla();

};

#endif
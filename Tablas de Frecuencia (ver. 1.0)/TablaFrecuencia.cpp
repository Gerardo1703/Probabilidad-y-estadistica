#include "TablaFrecuencia.hpp"
#include <iostream>

TablaFrecuencia::TablaFrecuencia(vector<double> d){
    datos = d;
    clases = {"<15", "15-18", "18-21", ">21"};
    frecuencia = {0,0,0,0};
}

void TablaFrecuencia::CalcularFrecuencias(){
    for(double valor : datos){
        if(valor <15)
        frecuencia[0]++;
        else if(valor <18)
        frecuencia[1]++;
        else if(valor <21)
        frecuencia[2]++;
        else
        frecuencia[3]++;
    }
}

void TablaFrecuencia::ImprimirTabla(){
    int n = datos.size();

    cout << "Tabla de Frecuencias\n\n";
    cout << "Clase\tf\tfr\t%\n";

    for(int i = 0; i < clases.size(); i++){
        double fr = (double)frecuencia[i] / n;

        cout << clases[i] << "\t" << frecuencia[i] << "\t" << fr << "\t" << fr*100 << "%" << endl;
    }
    cout << "Total\t" << n << "\t1.00\t100%" << endl;
}
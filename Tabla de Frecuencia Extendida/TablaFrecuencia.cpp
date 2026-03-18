#include "TablaFrecuencia.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

TablaFrecuencia::TablaFrecuencia(vector<double> d) {

    datos = d;
    n = datos.size();
}

void TablaFrecuencia::calcularClases() {

    minimo = datos[0];
    maximo = datos[0];

    for(double v : datos) {

        if(v < minimo) minimo = v;
        if(v > maximo) maximo = v;
    }

    k = round(1 + 3.322 * log10(n));

    amplitud = ceil((maximo - minimo) / k);

    limiteInferior.resize(k);
    limiteSuperior.resize(k);
    puntoMedio.resize(k);

    f.resize(k,0);
    Fa.resize(k,0);

    fr.resize(k,0);
    Fra.resize(k,0);

    double li = minimo;

    for(int i=0;i<k;i++) {

        limiteInferior[i] = li;
        limiteSuperior[i] = li + amplitud;

        puntoMedio[i] = (limiteInferior[i] + limiteSuperior[i]) / 2;

        li += amplitud;
    }
}

void TablaFrecuencia::calcularFrecuencias() {

    for(double v : datos) {

        for(int i=0;i<k;i++) {

            if(v >= limiteInferior[i] && v < limiteSuperior[i]) {

                f[i]++;
                break;
            }
        }
    }

    int acumulada = 0;
    double acumuladaRel = 0;

    for(int i=0;i<k;i++) {

        acumulada += f[i];
        Fa[i] = acumulada;

        fr[i] = (double)f[i] / n;

        acumuladaRel += fr[i];
        Fra[i] = acumuladaRel;
    }
}

void TablaFrecuencia::imprimirTabla() {

    cout << "Clase\tLimite\t\tf\tXc\tFa\tfr\tFra\t%\n";

    for(int i=0;i<k;i++) {

        cout << i+1 << "\t" << limiteInferior[i] << "-" << limiteSuperior[i] << "\t" << f[i] << "\t" << puntoMedio[i] << "\t" << Fa[i] << "\t" << fixed << setprecision(2) << fr[i] << "\t" << Fra[i] << "\t" << fr[i]*100 << "%\n" << endl;
    }

    cout << "Total\t\t" << n << "\t\t\t\t1.00\t\t100%\n" << endl;
}
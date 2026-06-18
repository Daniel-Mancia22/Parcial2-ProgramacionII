#ifndef EJECUTIVO_H_INCLUDED
#define EJECUTIVO_H_INCLUDED
#include "Empleado.h"

using namespace std;

class Ejecutivo : public Empleado{
    private:
        int carteraAsignada;

    public:
        Ejecutivo(int c, string n, string a, int carteraA): Empleado (c, n, a){
            this -> carteraAsignada = carteraA;
        }

        void setCartera(int carteraA){
            this -> carteraAsignada = carteraA;
        }

        int getCartera(){
            return this -> carteraAsignada;
        }

        string getNombrePuesto(){
            return "Ejecutivo";
        }
};

#endif // EJECUTIVO_H_INCLUDED

#ifndef CAJERO_H_INCLUDED
#define CAJERO_H_INCLUDED
#include "Empleado.h"

using namespace std;

class Cajero : public Empleado{
    private:
        int cajaAsignada;

    public:
        Cajero(int c, string n, string a, int cajaA): Empleado (c, n, a){
            this -> cajaAsignada = cajaA;
        }

        int getCajaAsignada(){
            return this -> cajaAsignada;
        }

        string getNombrePuesto(){
            return "Cajero";
        }
};

#endif // CAJERO_H_INCLUDED

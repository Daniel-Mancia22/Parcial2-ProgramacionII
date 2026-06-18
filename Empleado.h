#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "Persona.h"
#include "string.h"

using namespace std;

class Empleado : public Persona{
    private:
        float sueldo;

    public:
        Empleado(int c, string n, string a): Persona (c, n, a){
        }

        void setSueldo(float s){
            this -> sueldo = s;
        }

        float getSueldo(){
            return this -> sueldo;
        }

        virtual string getNombrePuesto()=0;
};

#endif // EMPLEADO_H_INCLUDED

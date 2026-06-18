#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "string.h"

using namespace std;

class Persona{
    private:
        int Codigo;
        string Nombre;
        string Apellido;

    public:
        Persona(int c, string n, string a){
            this -> Codigo = c;
            this -> Nombre = n;
            this -> Apellido = a;
        }

        int getCodigo(){
            return this -> Codigo;
        }

        string getNombreCompleto(){
                return this -> Nombre + " " + this -> Apellido;
        }
};

#endif // PERSONA_H_INCLUDED

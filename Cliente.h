#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "Persona.h"

using namespace std;

class Cliente : public Persona{
    private:
        string nit;

    public:
        Cliente(int c, string n, string a): Persona(c, n, a){
        }

        void setNit(string NIT){
            this -> nit = NIT;
        }

        string getNit(){
            return this -> nit;
        }

        virtual int getTipoCliente() = 0;
};

#endif // CLIENTE_H_INCLUDED

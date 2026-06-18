#ifndef CLIENTEPERSONAJURIDICA_H_INCLUDED
#define CLIENTEPERSONAJURIDICA_H_INCLUDED
#include "Cliente.h"
#include "Persona.h"

using namespace std;

class ClientePersonaJuridica : public Cliente{
    private:
        Persona *representanteLegal;

    public:
        ClientePersonaJuridica(int c, string n):Cliente(c, n,""){
        }

        void setRepresentanteLegal(Persona *rL){
            this -> representanteLegal = rL;
        }

        Persona *getRepresentanteLegal(){
            return this->representanteLegal;
        }

        int getTipoCliente(){
            return 2;
        }
};

#endif // CLIENTEPERSONAJURIDICA_H_INCLUDED

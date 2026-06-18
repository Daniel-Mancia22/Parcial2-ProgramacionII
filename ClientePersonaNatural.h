#ifndef CLIENTEPERSONANATURAL_H_INCLUDED
#define CLIENTEPERSONANATURAL_H_INCLUDED
#include "Cliente.h"
#include "Fecha.h"

using namespace std;

class ClientePersonaNatural : public Cliente{
    private:
        string dui;
        Fecha *fechaNac;

    public:
        ClientePersonaNatural(int c, string n, string a) : Cliente (c,n,a){
        }

        void setDui(string DUI){
            this -> dui = DUI;
        }

        string getDui(){
            return this -> dui;
        }

        void setFechaNac(Fecha *fN){
            this -> fechaNac = fN;
        }

        Fecha *getFechaNac(){
            return this -> fechaNac;
        }

        int getTipoCliente(){
                return 1;
        }
};

#endif // CLIENTEPERSONANATURAL_H_INCLUDED

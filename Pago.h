#ifndef PAGO_H_INCLUDED
#define PAGO_H_INCLUDED
#include "Cajero.h"
#include "Fecha.h"

using namespace std;

class Pago{
    private:
        int numeroCuota;
        Fecha *fechaPago;
        float monto;
        Cajero *cajeroAtendio;

    public:
        Pago(){
            this->numeroCuota = 0;
        }

        Pago(int nC, Fecha *fP, float m){
            this -> numeroCuota = nC;
            this -> fechaPago = fP;
            this -> monto = m;
        }

        void setCajeroAtendio(Cajero *cA){
            this -> cajeroAtendio = cA;
        }

        Cajero *getCajeroAtendio(){
            return this -> cajeroAtendio;
        }

        void setNumeroCuota(int nC){
            this -> numeroCuota = nC;
        }

        int getNumeroCuota(){
            return this -> numeroCuota;
        }

        Fecha *getFechaPago(){
            return this -> fechaPago;
        }

        float getMonto(){
            return this -> monto;
        }
};

#endif // PAGO_H_INCLUDED

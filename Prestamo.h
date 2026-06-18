#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include "Ejecutivo.h"
#include "Pago.h"
#include "Fecha.h"

using namespace std;

class Prestamo{
    private:
        int idPrestamo;
        int plazo;
        float couta;
        Cliente *cliente;
        Ejecutivo *ejecutivoCredito;
        Fecha *fecha;
        float montoAprobado;
        Pago *listaPagos[TAM];
        float saldoPendiente;
        int contadorPagos;

    public:
        Prestamo(int idP, int p, float mA){
            this -> idPrestamo = idP;
            this -> plazo = p;
            this -> montoAprobado = mA;
            this -> contadorPagos = 0;
            this -> saldoPendiente = this -> montoAprobado;
            this -> couta = this -> montoAprobado / this -> plazo;
        }

        int getIdPrestamo(){
            return this -> idPrestamo;
        }

        float getPlazo(){
            return this -> plazo;
        }

        float getCuota(){
            return this -> couta;
        }

        void setCliente(Cliente *cliente){
            this -> cliente = cliente;
        }

        Cliente *getCliente(){
            return this -> cliente;
        }

        void setEjecutivo(Ejecutivo *ejecutivoC){
            this -> ejecutivoCredito = ejecutivoC;
        }

        Ejecutivo *getEjecutivo(){
            return this -> ejecutivoCredito;
        }

        void setFecha(Fecha *f){
            this -> fecha = f;
        }
        Fecha *getFecha(){
            return this -> fecha;
        }

        float getMontoAprobado(){
            return this -> montoAprobado;
        }

        void registrarPago(Pago *p){
            if(this -> contadorPagos < TAM){
               if (this->contadorPagos < TAM){
                    this->listaPagos[this->contadorPagos] = p;
                    this->saldoPendiente = this->saldoPendiente - p->getMonto();
                    this->contadorPagos++;
                }
            }
        }

        Pago **getListaPagos() {
            return this -> listaPagos;
        }

        float getSaldoPendiente(){
            return this -> saldoPendiente;
        }

        int getContadorPagos(){
            return this -> contadorPagos;
        }
};

#endif // PRESTAMO_H_INCLUDED

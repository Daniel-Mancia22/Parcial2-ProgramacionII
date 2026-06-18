#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <sstream>  // for string streams

using namespace std;

class Fecha{
    private:
        int dia;
        int mes;
        int anio;

    public:
        Fecha(int d, int me, int a){
            this -> dia = d;
            this -> mes = me;
            this -> anio = a;
        }

        string mostrarFecha(){
            ostringstream dia,mes,anio;

            dia << this -> dia;
            mes << this -> mes;
            anio << this -> anio;

            string fecha = dia.str()+ "/" + mes.str()+"/"+ anio.str();

            return fecha;
        }
};

#endif // FECHA_H_INCLUDED

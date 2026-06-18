#include <iostream>
#include <stdlib.h>
#define TAM 4
#include "Ejecutivo.h"
#include "Cajero.h"
#include "ClientePersonaNatural.h"
#include "ClientePersonaJuridica.h"
#include "Prestamo.h"

using namespace std;

int menu(){
    int op;

    cout<<"********************************\n";
    cout<<"Menu de opciones\n";
    cout<<"********************************\n";
    cout<<"1.Agregar nuevo prestamos\n";
    cout<<"2.Registrar pagos\n";
    cout<<"3.Mostrar lista de prestamos\n";
    cout<<"4.Mostrar detalle de prestamo\n";
    cout<<"5.Salir\n";
    cout<<"********************************\n";
    cout<<"Digite una opcion: ";
    cin>>op;

    return op;
}

int buscarCliente(Cliente *listaCliente[], int id){

    //Variables
    bool buscar = false;
    int cont = 0;
    int pos = -1;

    while(!buscar && cont < 4){
        if(listaCliente[cont]->getCodigo() == id){
            buscar = true;
            pos = cont;
        }
        else{
            cont++;
        }
    }
    return pos;
}

int buscarEmpleado(Empleado *listaEmpleado[], int id){

    bool buscar = false;
    int cont = 0;
    int pos = -1;

    while(!buscar && cont < 4){
        if(listaEmpleado[cont]->getCodigo() == id){
            buscar = true;
            pos = cont;
        }
        else{
            cont++;
        }
    }
    return pos;
}

int buscarPrestamo(Prestamo *listaPrestamo[], int id){

    bool buscar = false;
    int cont = 0;
    int pos = -1;

    while(!buscar && cont < 4){
        if(listaPrestamo[cont]->getIdPrestamo() == id){
            buscar = true;
            pos = cont;
        }
        else{
            cont++;
        }
    }
    return pos;
}

Prestamo *agregarPrestamo(Cliente *listaCliente[], Empleado *listaEmpleado[]){

    int idC, idE;
    int idP, plazo;
    float mont, d,me,a;
    int posC, posE;
    Prestamo *prest=NULL;

    cout << "------------------------------\n";
    cout << "Digite el Id del cliente: ";
    cin >> idC;
    cout<<endl;

    posC = buscarCliente(listaCliente, idC);

    if(posC >= 0){
        cout << "Digite el Id del Ejecutivo: ";
        cin >> idE;

        posE = buscarEmpleado(listaEmpleado, idE);

        if(posE >= 0){
            cout << "------------------------------\n";
            cout << "Digite el Id del prestamo: ";
            cin >> idP;
            cout<<endl;

            cout << "Digite el Monto: ";
            cin >> mont;
            cout<<endl;

            cout << "Digite el Plazo: ";
            cin >> plazo;
            cout<<endl;

            cout << "Digite la Fecha dd/mm/aa: ";
            cin >> d;
            cin >> me;
            cin >> a;

            Fecha *fP = new Fecha(d,me,a);
            prest = new Prestamo(idP, plazo, mont);
            prest->setCliente(listaCliente[posC]);
            Ejecutivo *ej = (Ejecutivo*) listaEmpleado[posE];
            prest->setEjecutivo(ej);
            prest->setFecha(fP);
        }
        else{
            cout << "------------------------------\n";
            cout << "El empleado no existe"<<endl;
            cout << "------------------------------\n";
        }
    }
    else{
        cout << "------------------------------\n";
        cout << "El cliente no existe"<<endl;
        cout << "------------------------------\n";
    }
    return prest;
}

int main(){

    int opc, idP, nC, d, me, a, idCajera;
    float monto;
    Prestamo *listaPrestamo[TAM];
    int contadorP=0;

    Empleado *listaEmpleado[4];

    //2 Ejecutivo, 2 Cajeros
    listaEmpleado[0] = new Ejecutivo(1,"JOSUE","CRAMOS",1);
    listaEmpleado[1] = new Ejecutivo(2,"JUAN","PEREZ",2);
    listaEmpleado[2] = new Cajero(1, "JOSE", "GUZMAN", 1);
    listaEmpleado[3] = new Cajero(2, "ROSA", "GUTIERREZ", 2);


    //2 Persona Natural, 2 Persona juridica
    Cliente *listaCliente[4];
    listaCliente[0] = new ClientePersonaNatural(1,"MANUEL", "RIVAS");
    listaCliente[1] = new ClientePersonaNatural(2,"JULIA", "MARTINEZ");
    listaCliente[2] = new ClientePersonaJuridica(1,"REPUESTOS RIVAS");
    listaCliente[3] = new ClientePersonaJuridica(2,"REPUESTOS MARTINEZ");

    do{
        system("cls");
        opc = menu ();

        switch(opc){
            case 1:
                if(contadorP < TAM){
                    listaPrestamo[contadorP] = agregarPrestamo(listaCliente, listaEmpleado);
                    contadorP++;
                }
                else{
                    cout << "----------------------------------------------------\n";
                    cout << "No puede hacer su prestamos. La lista esta llena"<<endl;
                    cout << "----------------------------------------------------\n";
                }
                break;

            case 2:{
                cout << "------------------------------\n";
                cout << "Digite el Id del prestamo: ";
                cin >> idP;

                int posP = buscarPrestamo(listaPrestamo, idP);

                if(posP >= 0){
                        cout << "------------------------------\n";
                        cout << "Digite el Id del Cajero: ";
                        cin >> idCajera;

                        int posCajera = buscarEmpleado(listaEmpleado, idCajera);

                        if(posCajera >= 0){
                            cout << "Digite el numero de Cuota: ";
                            cin >> nC;

                            cout << "Digite la Fecha dd/mm/aa : ";
                            cin >> d;
                            cin >> me;
                            cin >> a;

                            Fecha *fP = new Fecha(d,me,a);

                            cout << "Digite el Monto: ";
                            cin >> monto;

                            Pago *p = new Pago(nC, fP, monto);
                            Cajero *cA = (Cajero*) listaEmpleado[posCajera];
                            p->setCajeroAtendio(cA);
                            listaPrestamo[posP]->registrarPago(p);
                        }
                        else{
                            cout << "----------------------------------------------\n";
                            cout << "No se encuentra ningun Cajero para este pago "<<endl;
                            cout << "----------------------------------------------\n";
                        }
                    }
                    else{
                        cout  << "El prestamo no existe"<<endl;
                        cout << "------------------------------\n";
                    }
                }
                break;

            case 3:{
                if(contadorP == 0){

                cout << "------------------------------\n";
                cout << "La lista esta vacia"<<endl;
                cout << "------------------------------\n";
                }
                else{
                    cout << "------------------------------\n";
                    cout << "Id\tCliente\tMonto "<<endl;

                    for(int i=0; i<contadorP; i++){
                        cout << listaPrestamo[i]->getIdPrestamo() << "\t";
                        cout << listaPrestamo[i]->getCliente()->getNombreCompleto() << "\t";
                        cout << listaPrestamo[i]->getMontoAprobado() << "\n";
                        }
                    }
                }
                break;

            case 4:{
                cout << "------------------------------\n";
                cout << "Digite el Id del prestamo: ";
                cin >> idP;

                int posP = buscarPrestamo(listaPrestamo, idP);

                if(posP >= 0){
                        Prestamo *aux = listaPrestamo[posP];

                        cout << "------------------------------\n";
                        cout << "Id prestamo: " << aux->getIdPrestamo()<<endl;
                        cout << "Cliente: " << aux->getCliente()->getNombreCompleto()<<endl;
                        cout << "Plazo: " << aux->getPlazo()<<endl;
                        cout << "Monto: " << aux->getMontoAprobado()<<endl;
                        cout << "Cuota: " << aux->getCuota() <<endl;
                        cout << "Eejecutivo: " << aux->getEjecutivo()->getNombreCompleto()<<endl;
                        cout << "Fecha: " << aux->getFecha()->mostrarFecha()<<endl;
                        cout << "Saldo pendiente: " << aux->getSaldoPendiente()<<endl;
                        cout<<endl;

                        Pago **lista = aux->getListaPagos();

                        cout << "------------------------------\n";
                        cout << "Numero\tFecha\tMonto\n";

                        for(int i=0; i<aux->getContadorPagos(); i++){
                            cout << lista[i]->getNumeroCuota() << "\t";
                            cout << lista[i]->getFechaPago()->mostrarFecha() << "\t";
                            cout << lista[i]->getMonto() << "\n";
                        }
                    }
                    else{
                        cout << "------------------------\n";
                        cout << "El prestamo no existe\n";
                        cout << "------------------------------\n";
                    }
                }
                break;

            case 5:{
                cout << "------------------------------\n";
                cout <<"Saliendo del programa"<<endl;
                cout << "------------------------------\n";
                }
                break;

            default:{
                cout << "------------------------------\n";
                cout <<"Opcion no definida\n";
                cout << "------------------------------\n";
                }
                break;
            }
            system("pause");
        }
        while(opc!=5);
    return 0;
}

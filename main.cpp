#include <iostream>
#include <wchar.h>
#include "funciones.h"    // el header de mis funciones
#include "rlutil.h"               // libreria pra mejorar la salida por pantalla
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8) ;

    //-------------------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------- MENÚ INICIO ----------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------

    int opc;
    string nombreJ1,nombreJ2, ganadorMaximo;

    string vHistoricoNom[ 3 ]= {};
    int vHistoricoPje[ 3 ]= {};

    srand(time(0));
    rlutil::saveDefaultColor();
    do
    {


        encabezado();
        cout<<endl<<endl;

        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(53,8);
        cout<<"1- JUGAR" <<endl;

        rlutil::locate(53,9);
        cout<<"2- ESTADISTICAS" <<endl;

        rlutil::locate(53,10);
        cout<<"3- CREDITOS"<<endl;

        rlutil::locate(53,11);
        cout<<"4- ♥♣ REGLAS DEL JUEGO ♦♠"<<endl;

        rlutil::locate(53,12);
        cout<<"0- SALIR"<<endl;

        rlutil::locate(53,14);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;

        system("cls");

        switch(opc)
        {
        case 1:
            Jugar( nombreJ1, nombreJ2, vHistoricoNom, vHistoricoPje );
            break;

        case 2:
            mostrarEstadisticas( vHistoricoNom, vHistoricoPje );
            break;

        case 3:
            cout<<"Proyecto desarrollado por:" <<endl;
            cout<<endl;
            cout<<"Enriquez Emmanuel, legajo 30321"<<endl;
            cout<<"Paz Lucia, legajo 29849"<<endl;
            cout<<"Tapia Julieta, legajo 28665"<<endl;
            cout<<endl;
            cout<<
                system("pause");
            system("cls");

            break;
        case 4:
            rlutil::locate(25,2);
            cout<< "El juego de cartas 'Embaucado' es un juego para dos jugadores";
            rlutil::locate(40,3);
            cout<<" que se juega en tres rondas.";
            rlutil::locate(20,4);
            cout<< "Cada jugador recibe cinco cartas al azar por ronda y hay una carta especial";
            rlutil::locate(30,5);
            cout<<" llamada embaucadora que determina qué cartas no suman puntos.";
            rlutil::locate(20,6);
            cout<<"El objetivo es acumular más puntos que tu oponente al final de las tres rondas.";

            rlutil::locate(42,8);
            cout<< "Modificación de la carta embaucadora:";
            rlutil::locate(15,9);
            cout<<"Desde la segunda ronda, los jugadores pueden sacrificar 20 puntos para cambiar la carta embaucadora";
            rlutil::locate(38,10);
            cout<<" si tienen al menos 20 puntos acumulados.";
            cout<<endl<<endl;
            rlutil::locate(43,28);
            system("pause");
            system("cls");
            break;
        case 0:
            cout<<"Gracias por jugar!"<<endl;
            return 0;
            break;

        default:
            cout<<"OPCION INCORRECTA"<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            break;

        }
    }
    while (opc != 0);
}


